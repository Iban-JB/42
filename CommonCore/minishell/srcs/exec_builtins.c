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

int	test_exec_builtin(t_minishell_info *shell_info, t_cmd_info *cmd, \
t_bool is_child, int fd);

int	exec_buitlin(t_minishell_info *shell_info, t_cmd_info *cmd, t_bool is_child)
{
	int			fd;
	int			return_builtin;
	t_builtins	builtin;

	builtin = is_builtin(cmd->cmd);
	fd = 1;
	if (is_child == false && builtin != not_builtin)
		fd = do_redirects(cmd, NULL, shell_info->gr_coll, is_child);
	if (fd == -1)
		return (shell_info->exit_value = 1, 1);
	return_builtin = test_exec_builtin(shell_info, cmd, is_child, fd);
	if (is_child == true && return_builtin != -1)
		ft_exit(shell_info, is_child, return_builtin, NULL);
	else if (is_child == false && return_builtin != -1)
		shell_info->exit_value = return_builtin;
	if (fd != 1)
		close_gr(shell_info->gr_coll, is_child, fd);
	return (return_builtin);
}

int	test_exec_builtin(t_minishell_info *shell_info, t_cmd_info *cmd, \
t_bool is_child, int fd)
{
	if (!ft_strcmp(cmd->cmd, ECHO))
		return (ft_echo(cmd->argv, fd));
	else if (!ft_strcmp(cmd->cmd, CD))
		return (ft_cd(cmd->argv, shell_info, is_child));
	else if (!ft_strcmp(cmd->cmd, PWD))
		return (ft_pwd(fd, shell_info->env));
	else if (!ft_strcmp(cmd->cmd, EXPORT))
		return (ft_export(shell_info, cmd->argv, is_child));
	else if (!ft_strcmp(cmd->cmd, UNSET))
		return (ft_unset(shell_info, cmd->argv, is_child));
	else if (!ft_strcmp(cmd->cmd, ENV))
		return (ft_env(shell_info->env, fd));
	else if (!ft_strcmp(cmd->cmd, EXIT))
		return (ft_exit(shell_info, is_child, EXIT_SUCCESS, cmd->argv));
	return (-1);
}
