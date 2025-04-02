/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:16:40 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/11 16:02:28 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exit_value	create_name(char **name, t_gr_coll *gr_coll);
void			replace_char(char *str);

static void		read_in_here_doc(char *limiter, t_bool limiter_quote, \
t_minishell_info *minishell_info, int fd);

t_bool	read_here_doc(char *limiter, char **name, \
t_minishell_info *minishell_info)
{
	int		fd_file_rand;
	t_bool	limiter_quote;

	create_name(name, minishell_info->gr_coll);
	fd_file_rand = open_gr(minishell_info->gr_coll, \
	open(*name, O_CREAT | O_WRONLY, 0777), false);
	if (fd_file_rand == -1)
		free_gr_all(minishell_info->gr_coll, 1, false);
	limiter_quote = has_quote_limiter(limiter);
	rl_event_hook = rl_hook_function;
	read_in_here_doc(limiter, limiter_quote, minishell_info, fd_file_rand);
	close_gr(minishell_info->gr_coll, false, fd_file_rand);
	free_node(minishell_info->gr_coll, limiter, false);
	return (g_sig == SIGINT);
}

t_exit_value	create_name(char **name, t_gr_coll *gr_coll)
{
	int	fd_open;
	int	len_tmp;

	len_tmp = ft_strlen(DOS_TMP);
	fd_open = open_gr(gr_coll, open(FILE_RANDOM, O_RDONLY), false);
	if (fd_open == -1)
		free_gr_all(gr_coll, 1, false);
	*name = malloc_gr(gr_coll, sizeof(char) * (25 + len_tmp), true, false);
	ft_strcpy(*name, DOS_TMP);
	if (read(fd_open, *name + len_tmp, 24) == -1)
		free_gr_all(gr_coll, 1, false);
	close_gr(gr_coll, false, fd_open);
	(*name)[24 + len_tmp] = 0;
	replace_char(*name + len_tmp);
	return (EXIT_WIN);
}

void	replace_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = (unsigned char)str[i] % 26 + 65;
		i++;
	}
}

static void	read_in_here_doc(char *limiter, t_bool limiter_quote, \
t_minishell_info *minishell_info, int fd)
{
	char	*md_line;
	char	*line;

	line = readline(">");
	if (line)
		add_node(line, minishell_info->gr_coll);
	else
		ft_dprintf(STDERR_FILENO, \
		"%s%shere-document delimited by end-of-file\n", MINISHELL, WARNING);
	while (cmp_here_doc_line(limiter, line) == false && g_sig != SIGINT)
	{
		md_line = modif_line_heredoc(line, limiter_quote, minishell_info);
		ft_dprintf(fd, "%s\n", md_line);
		free_node(minishell_info->gr_coll, md_line, false);
		line = readline(">");
		if (line)
			add_node(line, minishell_info->gr_coll);
		else
			ft_dprintf(STDERR_FILENO, \
		"%s%shere-document delimited by end-of-file\n", MINISHELL, WARNING);
	}
	if (line)
		free_node(minishell_info->gr_coll, line, false);
}
