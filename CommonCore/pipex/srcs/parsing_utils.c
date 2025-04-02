/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:33:27 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/25 16:54:21 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "error_msg.h"

void	get_commands_no_path(t_data *data)
{
	data->path_cmd1 = ft_strdup(data->cmd1[0]);
	if (!data->path_cmd1)
		exit_error(data, ERR_MSG4);
	data->path_cmd2 = ft_strdup(data->cmd2[0]);
	if (!data->path_cmd2)
		exit_error(data, ERR_MSG4);
	try_to_access(data->path_cmd1, &data->exec1, 0);
	try_to_access(data->path_cmd2, &data->exec2, 0);
}

void	get_abs_path(t_data *data, char **cmd, char **path, int *exec)
{
	*(path) = ft_strdup(cmd[0]);
	if (!*(path))
		exit_error(data, ERR_MSG4);
	try_to_access(*(path), exec, 0);
}

int	try_to_access(char *path_cmd, int *exec, int try)
{
	if (!access(path_cmd, F_OK))
	{
		if (!access(path_cmd, X_OK))
		{
			*exec = 1;
			return (1);
		}
		else
		{
			*exec = 0;
			ft_putstr_fd(path_cmd, 2);
			ft_putendl_fd(PB_MSG4, 2);
		}
	}
	else if (access(path_cmd, F_OK) && !try)
	{
		*exec = 0;
		ft_putstr_fd(path_cmd, 2);
		ft_putendl_fd(PB_MSG5, 2);
	}
	return (0);
}

void	create_path(t_data *data, char **cmd, char **path_cmd, int *exec)
{
	int		i;
	char	*tp;
	char	*new_path;

	i = -1;
	while (data->path[++i])
	{
		tp = ft_strjoin(data->path[i], "/");
		if (!tp)
			exit_error(data, ERR_MSG6);
		new_path = ft_strjoin(tp, cmd[0]);
		free(tp);
		if (!new_path)
			exit_error(data, ERR_MSG6);
		if (!try_to_access(new_path, exec, 1))
			free(new_path);
		else
		{
			*path_cmd = new_path;
			return ;
		}
	}
	*(exec) = 0;
	ft_putstr_fd(cmd[0], 2);
	ft_putendl_fd(PB_MSG5, 2);
}
