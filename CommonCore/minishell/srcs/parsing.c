/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:17:48 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/11 16:10:04 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_info_crt_cmd(char *line, t_info_crt_cmd *info_crt_cmd, \
t_minishell_info *minishell_info);

t_bool		verif_add_arg(t_minishell_info *minishell_info, \
t_info_crt_cmd *info_crt_cmd, t_list **lst_cmd);

void	parse_line(t_minishell_info *minishell_info)
{
	t_list	*lst;

	if (line_is_empty(minishell_info->parsing_info->line) == false)
	{
		g_sig = 0;
		add_history(minishell_info->gr_coll->line);
		remove_quotes(minishell_info->parsing_info);
		if (check_error_first_arg(minishell_info) == true)
		{
			minishell_info->exit_value = EXIT_PARSING;
			return ;
		}
		lst = crt_lst_cmd(minishell_info->parsing_info->line, minishell_info);
		add_file_temp_lst(lst, minishell_info);
		if (minishell_info->error == false && g_sig != SIGINT)
			execute_line(minishell_info, lst);
		else if (g_sig == SIGINT)
			minishell_info->exit_value = 130;
		else
			minishell_info->exit_value = EXIT_PARSING;
		ft_lstclear_gr(&lst, free_cmd_info, minishell_info->gr_coll, false);
	}
}

t_list	*crt_lst_cmd(char *line, t_minishell_info *minishell_info)
{
	t_info_crt_cmd	info_crt_cmd;
	t_list			*lst_cmd;

	init_info_crt_cmd(line, &info_crt_cmd, minishell_info);
	lst_cmd = NULL;
	if (verif_add_arg(minishell_info, &info_crt_cmd, &lst_cmd) == false)
		return (lst_cmd);
	while (line[info_crt_cmd.start_end[1]])
	{
		init_info_crt_cmd(NULL, &info_crt_cmd, minishell_info);
		if (verif_add_arg(minishell_info, &info_crt_cmd, &lst_cmd) == false)
			return (lst_cmd);
	}
	free_node(minishell_info->gr_coll, info_crt_cmd.start_end, false);
	if (info_crt_cmd.before_arg != other)
		return (minishell_info->error = \
		create_new_error(ERROR_UNEXPECTED_TOKEN, "`newline'", NULL), lst_cmd);
	minishell_info->error = false;
	return (lst_cmd);
}

t_bool	verif_add_arg(t_minishell_info *minishell_info, \
t_info_crt_cmd *info_crt_cmd, t_list **lst_cmd)
{
	if (info_crt_cmd->start_end[1] == -1)
	{
		free_node(minishell_info->gr_coll, info_crt_cmd->start_end, false);
		minishell_info->error = true;
		return (create_new_error(ERROR_LINE_NOT_FINISH, "", NULL), false);
	}
	if (info_crt_cmd->start_end[0] != info_crt_cmd->start_end[1])
	{
		if (add_info_cmd(lst_cmd, info_crt_cmd) == EXIT_PARSING)
		{
			minishell_info->error = true;
			return (false);
		}
	}
	return (true);
}

static void	init_info_crt_cmd(char *line, t_info_crt_cmd *info_crt_cmd, \
t_minishell_info *minishell_info)
{
	int	end;

	if (line)
	{
		info_crt_cmd->start_end = find_next_arg(line, 0, \
		minishell_info->gr_coll);
		info_crt_cmd->envp = minishell_info->env;
		info_crt_cmd->line = line;
		info_crt_cmd->before_arg = other;
		info_crt_cmd->exit_value = minishell_info->exit_value;
		info_crt_cmd->gr_coll = minishell_info->gr_coll;
		info_crt_cmd->end = 0;
	}
	else
	{
		end = info_crt_cmd->start_end[1];
		free_node(minishell_info->gr_coll, \
		info_crt_cmd->start_end, false);
		info_crt_cmd->start_end = find_next_arg(info_crt_cmd->line, \
		end, minishell_info->gr_coll);
	}
}
