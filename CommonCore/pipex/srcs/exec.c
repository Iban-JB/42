/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:33:12 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/25 16:51:45 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "error_msg.h"

void	wait_children(t_data *data, int *last_process)
{
	if (data->exec1)
		*last_process = waitpid(data->id1, &data->status1, 0);
	if (data->status1 < 0)
		child_error(data->status1, 1);
	if (data->exec2)
		*last_process = waitpid(data->id2, &data->status2, 0);
	if (data->status2 < 0)
		child_error(data->status2, 2);
}

void	first_child_process(t_data *data)
{
	if (dup2(data->fd_infile, STDIN_FILENO) == -1)
		exit(-2);
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
		exit(-2);
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->fd_infile);
	close(data->fd_outfile);
	execve(data->path_cmd1, data->cmd1, data->envp);
	free_data(data);
	exit(-1);
}

void	second_child_process(t_data *data)
{
	if (dup2(data->fd[0], STDIN_FILENO) == -1)
		exit(-2);
	if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
		exit(-2);
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->fd_outfile);
	execve(data->path_cmd2, data->cmd2, data->envp);
	free_data(data);
	exit(-1);
}

void	start_process(t_data *data, int *last_process)
{
	if (data->exec1)
	{
		data->id1 = fork();
		if (data->id1 == -1)
			exit_error(data, ERR_MSG5);
		else if (!data->id1)
			first_child_process(data);
	}
	if (data->fd[1] > 2)
		close(data->fd[1]);
	if (data->fd_infile)
		close(data->fd_infile);
	if (data->id1 != 0 && data->exec2)
	{
		data->id2 = fork();
		if (data->id2 == -1)
			exit_error(data, ERR_MSG5);
		else if (!data->id2)
			second_child_process(data);
	}
	close(data->fd[0]);
	close(data->fd_outfile);
	if (data->id1 && data->id2)
		wait_children(data, last_process);
}
