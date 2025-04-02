/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:34:52 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/12 14:32:13 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_error_exit(char **argv, int *value_return);

int	ft_pwd(int fd, char **envp)
{
	char	pwd[4096];
	int		value_pwd;

	if (getcwd(pwd, 4095) != NULL)
		ft_dprintf(fd, "%s\n", pwd);
	else
	{
		value_pwd = find_id_var_env(envp, "PWD", 3);
		if (value_pwd != -1)
			ft_dprintf(fd, "%s\n", envp[value_pwd] + 4);
		else
		{
			ft_dprintf(STDERR_FILENO, "%s%s: %s\n", MINISHELL, PWD, \
strerror(errno));
			return (1);
		}
	}
	return (0);
}

int	ft_exit(t_minishell_info *shell_info, t_bool is_child, \
int value_return, char **argv)
{
	if (argv || value_return == -1)
		printf("exit\n");
	if (argv && argv[1])
	{
		if (ft_error_exit(argv, &value_return) == 1)
			return (1);
	}
	else if ((argv && !argv[1]) || value_return == -1)
		value_return = shell_info->exit_value;
	if (shell_info->type_data)
		ft_lstclear_gr(&shell_info->type_data, free_cmd_info, \
		shell_info->gr_coll, is_child);
	free_gr_all(shell_info->gr_coll, value_return, is_child);
	return (0);
}

static int	ft_error_exit(char **argv, int *value_return)
{
	t_bool	error_st_arg;

	error_st_arg = char_is_number(*(argv + 1));
	if (error_st_arg == false)
	{
		ft_dprintf(STDERR_FILENO, \
			"%s%s :%s%s\n", MINISHELL, EXIT, *(argv + 1), NUMERIC_ARG);
		*value_return = 2;
	}
	else
		*value_return = ft_atoi(*(argv + 1));
	if (error_st_arg == true && argv[2])
		return (ft_dprintf(STDERR_FILENO, \
			"%s%s%s\n", MINISHELL, EXIT, TOO_MANY_ARGS), 1);
	return (0);
}

int	ft_echo(char **argv, int fd)
{
	t_bool	is_jump;
	int		i;

	i = only_n_flags(argv);
	if (argv[1] != NULL && i > 1)
		is_jump = true;
	else
		is_jump = false;
	while (argv[i])
	{
		ft_dprintf(fd, "%s", argv[i]);
		if (argv[i + 1])
			ft_dprintf(fd, " ");
		i++;
	}
	if (is_jump == false)
		ft_dprintf(fd, "\n");
	return (0);
}

int	ft_unset(t_minishell_info *minishell_info, char **name, t_bool is_child)
{
	int	i;
	int	j;

	j = 0;
	while (name[++j])
	{
		if (ft_isdigit(*(name[j])))
			return (ft_dprintf(STDERR_FILENO, "%s%s: `%s': %s\n", \
MINISHELL, UNSET, name[j], INVALID_IDENTIFIER), 1);
		i = -1;
		while (name[j][++i])
			if (!ft_isalnum((int) name[j][i]) && name[j][i] != '_')
				return (ft_dprintf(STDERR_FILENO, "%s%s: `%s': %s\n", \
MINISHELL, UNSET, name[j], INVALID_IDENTIFIER), 1);
		minishell_info->env = unset_var_env(name[j], minishell_info->env, \
minishell_info, is_child);
		if (!minishell_info->env)
			return (-1);
	}
	return (0);
}
