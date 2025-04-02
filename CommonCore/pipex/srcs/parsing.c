/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:33:29 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/25 16:54:21 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "error_msg.h"

void	open_files(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	data->fd_infile = fd;
	if (data->fd_infile == -1)
	{
		data->exec1 = 0;
		ft_putendl_fd(PB_MSG2, 2);
	}
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	data->fd_outfile = fd;
	if (data->fd_outfile == -1)
	{
		data->exec2 = 0;
		ft_putendl_fd(PB_MSG3, 2);
	}
}

void	get_commands(t_data *data, char **argv)
{
	data->cmd1 = ft_split(argv[2], ' ');
	if (!data->cmd1)
		exit_error(data, ERR_MSG3);
	data->cmd2 = ft_split(argv[3], ' ');
	if (!data->cmd2)
		exit_error(data, ERR_MSG3);
}

void	get_path_commands(t_data *data)
{
	if (data->path)
	{
		if (data->exec1 && data->cmd1[0])
		{
			if (data->cmd1[0] && ft_strchr(data->cmd1[0], '/'))
				get_abs_path(data, data->cmd1, &data->path_cmd1, &data->exec1);
			else if (data->cmd1[0])
				create_path(data, data->cmd1, &data->path_cmd1, &data->exec1);
		}
		else
			data->exec1 = 0;
		if (data->exec2 && data->cmd2[0])
		{
			if (data->cmd2[0] && ft_strchr(data->cmd2[0], '/'))
				get_abs_path(data, data->cmd2, &data->path_cmd2, &data->exec2);
			else if (data->cmd2[0])
				create_path(data, data->cmd2, &data->path_cmd2, &data->exec2);
		}
		else
			data->exec2 = 0;
	}
	else
		get_commands_no_path(data);
}

void	get_path(t_data *data)
{
	size_t	i;
	char	**env;

	env = data->envp;
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (env[i] && !ft_strncmp(env[i], "PATH=", 5))
	{
		data->path = ft_split(env[i] + 5, ':');
		if (!data->path)
			exit_error(data, ERR_MSG3);
	}
	else
		data->path = NULL;
}
