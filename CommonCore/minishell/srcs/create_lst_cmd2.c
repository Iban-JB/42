/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_cmd2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:07:24 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 14:01:42 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			fill_file_info(t_info_crt_cmd *info_crt_cmd, \
t_type_arg before_arg, t_file_info *file_info);

static t_exit_value	add_file_in_lst(t_list **lst_file, t_info_crt_cmd \
*info_crt_cmd, t_type_arg before_arg);
static char			*create_pattern_here_doc(t_info_crt_cmd *info_crt_cmd);

t_exit_value	add_argv_cmd_in_cmd(t_list **cmd, t_info_crt_cmd *info_crt_cmd)
{
	char	**pattern;
	int		i;

	pattern = create_pattern(info_crt_cmd);
	i = -1;
	if (pattern)
	{
		while (pattern[++i])
		{
			if (!((t_cmd_info *)(*cmd)->content)->cmd)
				((t_cmd_info *)(*cmd)->content)->cmd = pattern[i];
			((t_cmd_info *)(*cmd)->content)->argv = \
			add_str_double_tab(((t_cmd_info *)(*cmd)->content)->argv, \
			pattern[i], info_crt_cmd->gr_coll, false);
		}
		free_node(info_crt_cmd->gr_coll, pattern, false);
	}
	return (EXIT_WIN);
}

t_exit_value	add_cmd_or_file(t_list *last_cmd, \
t_info_crt_cmd *info_crt_cmd, t_type_arg before_arg)
{
	if (before_arg == pipe_char)
	{
		last_cmd->next = create_cmd_info(info_crt_cmd->gr_coll);
		if (!last_cmd->next)
			return (EXIT_FAIL);
		add_argv_cmd_in_cmd(&last_cmd->next, info_crt_cmd);
		return (EXIT_WIN);
	}
	return (add_file_in_lst(&((t_cmd_info *) \
	last_cmd->content)->file_info_list, info_crt_cmd, before_arg));
}

static t_exit_value	add_file_in_lst(t_list **lst_file, \
t_info_crt_cmd *info_crt_cmd, t_type_arg before_arg)
{
	t_file_info	*file_info;
	t_list		*elmnt_file;

	file_info = malloc_gr(info_crt_cmd->gr_coll, \
	sizeof(t_file_info), false, false);
	fill_file_info(info_crt_cmd, before_arg, file_info);
	elmnt_file = lstnew_gr(file_info, info_crt_cmd->gr_coll);
	ft_lstadd_back(lst_file, elmnt_file);
	return (EXIT_WIN);
}

static void	fill_file_info(t_info_crt_cmd *info_crt_cmd, \
t_type_arg before_arg, t_file_info *file_info)
{
	char	**tab_pattern;

	file_info -> error = false;
	if (before_arg == here_doc)
		file_info->name_file = create_pattern_here_doc(info_crt_cmd);
	else
	{
		tab_pattern = create_pattern(info_crt_cmd);
		if (ft_len_tab_str(tab_pattern) == 0 || \
		ft_len_tab_str(tab_pattern) > 1)
		{
			free_tab_str(tab_pattern, -1, \
			info_crt_cmd->gr_coll, false);
			file_info->name_file = get_arg_line(info_crt_cmd);
			file_info->error = true;
		}
		else
		{
			file_info->name_file = *tab_pattern;
			free_node(info_crt_cmd->gr_coll, \
			tab_pattern, false);
		}
	}
	file_info->type_arg = before_arg;
}

static char	*create_pattern_here_doc(t_info_crt_cmd *info_crt_cmd)
{
	int		i;
	int		len;
	char	*pattern;

	i = info_crt_cmd->start_end[0] - 1;
	pattern = malloc_gr(info_crt_cmd->gr_coll, \
	sizeof(char) * (info_crt_cmd->start_end[1] - \
	info_crt_cmd->start_end[0] + 1), false, false);
	len = 0;
	while (++i < info_crt_cmd->start_end[1])
	{
		pattern[len] = info_crt_cmd->line[i];
		len++;
	}
	pattern[len] = 0;
	return (pattern);
}
