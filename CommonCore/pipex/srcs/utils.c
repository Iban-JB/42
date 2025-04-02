/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:11:54 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/21 15:15:02 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "error_msg.h"

void	free_tab_tab_char(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	child_error(int status, int child)
{
	if (child == 1)
		ft_putstr_fd("First child process : ", 2);
	else
		ft_putstr_fd("Second child process : ", 2);
	if (status == -1)
		ft_putendl_fd(PB_MSG6, 2);
	else if (status == -2)
		ft_putendl_fd(PB_MSG7, 2);
}

void	free_data(t_data *data)
{
	if (data->path_cmd1)
		free(data->path_cmd1);
	if (data->path_cmd2)
		free(data->path_cmd2);
	if (data->cmd1)
		free_tab_tab_char(data->cmd1);
	if (data->cmd2)
		free_tab_tab_char(data->cmd2);
	if (data->path)
		free_tab_tab_char(data->path);
}

void	exit_error(t_data *data, char *msg)
{
	free_data(data);
	perror(msg);
	exit(1);
}

void	init_data(t_data *data, char **argv, char **envp)
{
	data->envp = envp;
	if (pipe(data->fd))
		exit_error(data, ERR_MSG2);
	get_path(data);
	open_files(data, argv);
	get_commands(data, argv);
	get_path_commands(data);
}
