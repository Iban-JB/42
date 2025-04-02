/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_temp_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:54:03 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/16 14:55:35 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exit_value	add_file_temp_lst(t_list *lst_cmd,
t_minishell_info *minishell_info)
{
	t_file_info		*file_info;
	char			*name_file;
	t_list			*lst_file;

	while (lst_cmd)
	{
		lst_file = trans_lst_cmd_info(lst_cmd)->file_info_list;
		while (lst_file)
		{
			file_info = trans_lst_file_info(lst_file);
			if (file_info && file_info->type_arg == here_doc)
			{
				read_here_doc(file_info->name_file, &name_file, minishell_info);
				file_info->name_file = name_file;
			}
			rl_done = 0;
			rl_event_hook = NULL;
			lst_file = lst_file->next;
		}
		lst_cmd = lst_cmd->next;
	}
	return (EXIT_WIN);
}
