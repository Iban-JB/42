/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:40:24 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/10 20:54:06 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wait_for_children(t_minishell_info *shell_info, \
int max_process, pid_t last_process)
{
	int	i;
	int	status;
	int	waited_pid;

	i = -1;
	status = 0;
	signal(SIGQUIT, sig_quit_action);
	signal(SIGINT, sig_int_after_exec);
	while (++i < max_process)
	{
		waited_pid = waitpid(-1, &status, 2);
		if (last_process == waited_pid)
		{
			if (WIFEXITED(status))
				shell_info->exit_value = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				shell_info->exit_value = 128 + WTERMSIG(status);
		}
	}
	if (g_sig == SIGQUIT)
		ft_dprintf(STDERR_FILENO, "Quit (core dumped)\n");
	else if (g_sig == SIGINT)
		printf("\n");
	return (0);
}

void	execute_line(t_minishell_info *shell_info, t_list *lst_cmds)
{
	pid_t		last_id;
	t_pipe_info	pipe_info;
	int			i;

	pipe_info = (t_pipe_info){0};
	i = 0;
	shell_info->type_data = lst_cmds;
	if (lst_cmds->next || exec_buitlin(shell_info, \
	trans_lst_cmd_info(lst_cmds), false) == -1)
	{
		while (lst_cmds)
		{
			++i;
			if (lst_cmds->next)
				pipe_gr(pipe_info.fd, shell_info->gr_coll, false);
			else
				pipe_info.last = 1;
			last_id = create_child(shell_info, (t_cmd_info *)lst_cmds->content, \
			&pipe_info);
			lst_cmds = lst_cmds->next;
		}
		wait_for_children(shell_info, i, last_id);
	}
}
