/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:07:32 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/11 16:01:12 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_minishell_info(t_minishell_info *minshell_info)
{
	if (minshell_info->parsing_info)
		free_node(minshell_info->gr_coll, \
		minshell_info->parsing_info->line, false);
	free_tab_str(minshell_info->env, -1, minshell_info->gr_coll, false);
	if (minshell_info->parsing_info)
		free_node(minshell_info->gr_coll, \
		minshell_info->parsing_info->line, false);
	free_node(minshell_info->gr_coll, minshell_info->parsing_info, false);
	free_node(minshell_info->gr_coll, minshell_info, false);
}

void	free_cmd_info(void *cmd_info_base, t_gr_coll *gr_coll, t_bool is_child)
{
	t_cmd_info	*cmd_info;

	cmd_info = (t_cmd_info *)cmd_info_base;
	free_node(gr_coll, cmd_info->cmd, is_child);
	if (cmd_info->argv)
		free_tab_str(cmd_info->argv, -1, gr_coll, is_child);
	if (cmd_info->file_info_list)
		ft_lstclear_gr(&cmd_info->file_info_list, \
		free_file_info, gr_coll, is_child);
	free_node(gr_coll, cmd_info, is_child);
}

void	free_file_info(void *file_info, t_gr_coll *gr_coll, t_bool is_child)
{
	free_node(gr_coll, ((t_file_info *)file_info)->name_file, is_child);
	free_node(gr_coll, file_info, is_child);
}
