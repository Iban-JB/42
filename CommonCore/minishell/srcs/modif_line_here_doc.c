/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_line_here_doc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:29:00 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/14 13:34:07 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		fill_line_here_doc(char *readline, char *new_line, \
char **envp, int exit_value);

char	*modif_line_heredoc(char *readline, \
t_bool has_quote, t_minishell_info *minishell_info)
{
	int		len;
	int		i;
	char	*new_line;

	if (has_quote == true)
		return (readline);
	i = 0;
	len = 0;
	while (readline[i])
	{
		if (readline[i] == '$')
		{
			len += len_var(&i, readline, minishell_info->env, \
			minishell_info->exit_value);
		}
		else
			len += i++ > -1;
	}
	new_line = malloc_gr(minishell_info->gr_coll, (len + 1) * \
	sizeof(char), false, false);
	fill_line_here_doc(readline, new_line, minishell_info->env, \
	minishell_info->exit_value);
	free_node(minishell_info->gr_coll, readline, false);
	return (new_line);
}

t_bool	has_quote_limiter(char *limiter)
{
	while (*limiter)
	{
		if (*limiter == -1 || *limiter == -2)
			return (true);
		limiter++;
	}
	return (false);
}

t_bool	cmp_here_doc_line(char *limiter, char *line)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!line)
		return (true);
	while (limiter[++i] && line[j])
	{
		if (limiter[i] != -1 && limiter[i] != -2)
		{
			if (line[j] != limiter[i])
				return (false);
			j++;
		}
	}
	if (line[j])
		return (false);
	return (true);
}

void	fill_line_here_doc(char *readline, \
char *new_line, char **envp, int exit_value)
{
	t_info_crt_cmd	info_crt_cmd;
	int				i;
	int				len;

	info_crt_cmd.envp = envp;
	info_crt_cmd.exit_value = exit_value;
	len = 0;
	i = -1;
	while (readline[++i])
	{
		if (readline[i] == '$')
		{
			len += fill_pattern_var(&i, \
			readline, &info_crt_cmd, new_line + len);
			i--;
		}
		else
			new_line[len++] = readline[i];
	}
	new_line[len] = 0;
}
