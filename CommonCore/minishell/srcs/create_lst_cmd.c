/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:17:06 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/16 14:56:43 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		is_comparator(t_info_crt_cmd *info_crt_cmd);
t_exit_value	create_error_comparator(t_info_crt_cmd *info_crt_cmd);

t_exit_value	add_info_cmd(t_list **cmd, t_info_crt_cmd *info_crt_cmd)
{
	t_type_arg	type_arg_before;
	t_list		*last_cmd;

	type_arg_before = info_crt_cmd->before_arg;
	if (!*cmd)
	{
		*cmd = create_cmd_info(info_crt_cmd->gr_coll);
		if (!*cmd)
			return (EXIT_FAIL);
	}
	last_cmd = ft_lstlast(*cmd);
	if (create_error_comparator(info_crt_cmd) == EXIT_PARSING)
		return (EXIT_PARSING);
	if (info_crt_cmd->before_arg != other)
		return (EXIT_WIN);
	if (type_arg_before == other)
		return (add_argv_cmd_in_cmd(&last_cmd, info_crt_cmd));
	return (add_cmd_or_file(last_cmd, info_crt_cmd, type_arg_before));
}

t_list	*create_cmd_info(t_gr_coll *gr_coll)
{
	t_list		*lst;
	t_cmd_info	*cmd_info;

	cmd_info = malloc_gr(gr_coll, sizeof(t_cmd_info), false, false);
	*cmd_info = (t_cmd_info){0};
	cmd_info->argv = malloc_gr(gr_coll, sizeof(char *), false, false);
	cmd_info->argv[0] = NULL;
	lst = lstnew_gr(cmd_info, gr_coll);
	return (lst);
}

static void	is_comparator(t_info_crt_cmd *info_crt_cmd)
{
	info_crt_cmd->before_arg = other;
	if (info_crt_cmd->start_end[1] - info_crt_cmd->start_end[0] == 1)
	{
		if (info_crt_cmd->line[info_crt_cmd->start_end[0]] == '>')
			info_crt_cmd->before_arg = outfile;
		else if (info_crt_cmd->line[info_crt_cmd->start_end[0]] == '<')
			info_crt_cmd->before_arg = infile;
		else if (info_crt_cmd->line[info_crt_cmd->start_end[0]] == '|')
			info_crt_cmd->before_arg = pipe_char;
	}
	else if (info_crt_cmd->start_end[1] - info_crt_cmd->start_end[0] == 2)
	{
		if (info_crt_cmd->line[info_crt_cmd->start_end[0]] == \
		'>' && info_crt_cmd->line[info_crt_cmd->start_end[0] + 1] == '>')
			info_crt_cmd->before_arg = append;
		else if (info_crt_cmd->line[info_crt_cmd->start_end[0]] == \
		'<' && info_crt_cmd->line[info_crt_cmd->start_end[0] + 1] == '<')
			info_crt_cmd->before_arg = here_doc;
	}
}

t_exit_value	create_error_comparator(t_info_crt_cmd *info_crt_cmd)
{
	t_bool	possible_error;
	t_bool	before_is_pipe;

	possible_error = false;
	before_is_pipe = false;
	if (info_crt_cmd->before_arg == pipe_char)
		before_is_pipe = true;
	if (info_crt_cmd->before_arg != other && info_crt_cmd->before_arg != \
	pipe_char)
		possible_error = true;
	is_comparator(info_crt_cmd);
	if ((info_crt_cmd ->before_arg != other && possible_error == true)
		|| (before_is_pipe == true && info_crt_cmd ->before_arg == pipe_char))
		return (create_new_error(ERROR_UNEXPECTED_TOKEN,
				info_crt_cmd->line, info_crt_cmd->start_end), EXIT_PARSING);
	return (EXIT_WIN);
}

char	*get_arg_line(t_info_crt_cmd *info_crt_cmd)
{
	char	c;
	char	*arg;

	c = info_crt_cmd->line[info_crt_cmd->start_end[1]];
	info_crt_cmd->line[info_crt_cmd->start_end[1]] = '\0';
	arg = strdup_gr(info_crt_cmd->line + info_crt_cmd->start_end[0], \
	info_crt_cmd->gr_coll, false);
	info_crt_cmd->line[info_crt_cmd->start_end[1]] = c;
	return (arg);
}
