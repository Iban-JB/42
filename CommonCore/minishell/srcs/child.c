/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:28:06 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/11 15:39:12 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child(t_minishell_info *shell_info, \
t_cmd_info *cmd_info, t_pipe_info *pipe_info)
{
	struct sigaction	act;
	char				*path_cmd;

	path_cmd = NULL;
	act = (struct sigaction){0};
	act.sa_handler = SIG_DFL;
	do_redirects(cmd_info, pipe_info, shell_info->gr_coll, true);
	if (!cmd_info->cmd)
		ft_exit(shell_info, true, 0, NULL);
	exec_buitlin(shell_info, cmd_info, true);
	if (cmd_info->cmd && ft_strchr(cmd_info->cmd, '/'))
	{
		check_directory_perms(shell_info, cmd_info->cmd);
		path_cmd = strdup_gr(cmd_info->cmd, shell_info->gr_coll, true);
	}
	else
		path_cmd = find_path_command(shell_info, cmd_info->cmd);
	if (!path_cmd)
		ft_exit(shell_info, true, 127, NULL);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	execve(path_cmd, cmd_info->argv, shell_info->env);
	free_node(shell_info->gr_coll, path_cmd, true);
	ft_exit(shell_info, true, 127, NULL);
}

pid_t	create_child(t_minishell_info *shell_info, \
t_cmd_info *cmd_info, t_pipe_info *pipe_info)
{
	pid_t	id_child;

	id_child = fork_gr(shell_info->gr_coll);
	if (!id_child)
		exec_child(shell_info, cmd_info, pipe_info);
	else
	{
		if (pipe_info)
		{
			if (!pipe_info->last)
				close_gr(shell_info->gr_coll, false, pipe_info->fd[1]);
			if (pipe_info->temp_fd)
				close_gr(shell_info->gr_coll, false, pipe_info->temp_fd);
			pipe_info->temp_fd = pipe_info->fd[0];
		}
		return (id_child);
	}
	return (0);
}
