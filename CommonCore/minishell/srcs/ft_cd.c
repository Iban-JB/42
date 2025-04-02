/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:34:36 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 16:32:43 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	modif_cd_not_arg(t_minishell_info *shell_info, t_bool is_child);
int	cd_with_arg(t_minishell_info *shell_info, char *arg, t_bool is_child);

int	ft_cd(char **argv, t_minishell_info *shell_info, t_bool is_child)
{
	size_t	argc;

	argc = ft_len_tab_str(argv);
	if (argc > 2)
		return (ft_dprintf(STDERR_FILENO, "%s%s%s\n", \
		MINISHELL, CD, TOO_MANY_ARGS), 1);
	if (argc == 1)
		return (modif_cd_not_arg(shell_info, is_child));
	return (cd_with_arg(shell_info, argv[1], is_child));
}

int	modif_cd_not_arg(t_minishell_info *shell_info, t_bool is_child)
{
	char	*value_home;
	char	*value_pwd;

	value_home = find_var_env(shell_info->env, HOME, 4);
	if (!value_home)
		return (ft_dprintf(STDERR_FILENO, "%s%s\n", MINISHELL, \
		HOME_NOT_SET), 1);
	value_pwd = find_var_env(shell_info->env, PWD_ENV, 3);
	if (!value_pwd)
	{
		shell_info->env = unset_var_env(OLDPWD, shell_info->env, \
		shell_info, is_child);
		if (!shell_info->env)
			return (-1);
	}
	else
		if (change_value_var_env(OLDPWD, value_pwd + 4, shell_info, true) == -2)
			return (-1);
	if (change_value_var_env(PWD_ENV, value_home + 5, shell_info, true) == -2)
		return (-1);
	if (chdir(value_home + 5) == -1)
		ft_dprintf(STDERR_FILENO, "%s%s: %s %s\n", MINISHELL, CD, \
value_home + 5, NO_EXIST);
	return (0);
}

int	cd_with_arg(t_minishell_info *shell_info, char *arg, t_bool is_child)
{
	char	*value_pwd;
	char	new_value_pwd[PATH_MAX];

	if (chdir(arg) == -1)
		return (ft_dprintf(STDERR_FILENO, "%s%s: %s: %s\n", MINISHELL, CD, \
		arg, strerror(errno)), 1);
	value_pwd = find_var_env(shell_info->env, PWD_ENV, 3);
	if (!value_pwd)
	{
		shell_info->env = unset_var_env(OLDPWD, \
		shell_info->env, shell_info, is_child);
		if (!shell_info->env)
			return (-1);
	}
	else
	{
		if (!getcwd(new_value_pwd, PATH_MAX - 1) || change_value_var_env(\
OLDPWD, value_pwd + 4, shell_info, is_child) == -2 || \
change_value_var_env(PWD_ENV, new_value_pwd, shell_info, is_child) == -2)
			return (-1);
	}
	return (0);
}
