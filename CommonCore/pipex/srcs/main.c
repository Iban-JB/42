/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:34:33 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/20 18:45:13 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "error_msg.h"
#include "libft.h"

void	data_null(t_data *data)
{
	data->exec1 = 1;
	data->exec2 = 1;
	data->id1 = -1;
	data->id2 = -1;
	data->status1 = 0;
	data->status2 = 0;
	data->path = NULL;
	data->path_cmd1 = NULL;
	data->path_cmd2 = NULL;
	data->cmd1 = NULL;
	data->cmd2 = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	pid_t	last_process;

	last_process = 0;
	if (argc == 5)
	{
		data_null(&data);
		init_data(&data, argv, envp);
		start_process(&data, &last_process);
		free_data(&data);
	}
	else
		ft_putendl_fd(ERR_MSG1, 2);
	return (last_process);
}
