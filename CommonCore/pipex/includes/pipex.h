/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:33:20 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/25 16:54:21 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_data
{
	int		fd[2];
	int		status1;	
	int		status2;
	int		exec1;
	int		exec2;
	int		fd_infile;
	int		fd_outfile;
	char	*path_cmd1;
	char	*path_cmd2;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	**envp;
	pid_t	id1;
	pid_t	id2;
	pid_t	last_process;
}	t_data;

void	init_data(t_data *data, char **argv, char **envp);
void	exit_error(t_data *data, char *msg);
void	open_files(t_data *data, char **argv);
void	get_commands(t_data *data, char **argv);
void	get_path(t_data *data);
void	get_path_commands(t_data *data);
void	get_abs_path(t_data *data, char **cmd, char **path, int *exec);
void	create_path(t_data *data, char **cmd, char **path_cmd, int *exec);
void	start_process(t_data *data, int *last_process);
void	child_error(int status, int child);
void	free_data(t_data *data);
int		try_to_access(char *path_cmd, int *exec, int try);
void	get_commands_no_path(t_data *data);

#endif