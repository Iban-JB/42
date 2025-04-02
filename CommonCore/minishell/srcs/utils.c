/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:48:13 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/12 14:41:31 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_directory_perms(t_minishell_info *shell_info, char *name)
{
	struct stat	path;

	stat(name, &path);
	if (S_ISDIR(path.st_mode))
	{
		ft_dprintf(STDERR_FILENO, "%s%s%s\n", MINISHELL, name, IS_DIR);
		ft_exit(shell_info, true, 126, NULL);
	}
	else if (access(name, F_OK))
	{
		ft_dprintf(STDERR_FILENO, "%s%s%s\n", MINISHELL, name, NO_EXIST);
		ft_exit(shell_info, true, 127, NULL);
	}
	else if (access(name, X_OK))
	{
		ft_dprintf(STDERR_FILENO, "%s%s%s\n", MINISHELL, name, NO_PERMS);
		ft_exit(shell_info, true, 126, NULL);
	}
}

t_bool	need_to_close_gr(int fd, t_type_arg ty_a)
{
	if (fd != 0 && fd != 1 && fd != -1 && (ty_a == infile || ty_a == here_doc))
		return (true);
	return (false);
}

t_builtins	is_builtin(char *name)
{
	if (!ft_strcmp(name, ECHO))
		return (echo);
	else if (!ft_strcmp(name, CD))
		return (cd);
	else if (!ft_strcmp(name, PWD))
		return (pwd);
	else if (!ft_strcmp(name, EXPORT))
		return (export);
	else if (!ft_strcmp(name, UNSET))
		return (unset);
	else if (!ft_strcmp(name, ENV))
		return (env);
	else if (!ft_strcmp(name, EXIT))
		return (ext);
	return (not_builtin);
}

int	error_redirection_arg(char *name, t_gr_coll *gr_coll, t_bool is_child)
{
	ft_dprintf(STDERR_FILENO, "%s%s%s\n", MINISHELL, name, AMBIGUOUS_RED);
	if (is_child == true)
		free_gr_all(gr_coll, 1, true);
	return (-1);
}

int	only_n_flags(char **str_flags)
{
	size_t	i;
	size_t	j;
	char	*tp;

	i = 1;
	while (str_flags[i])
	{
		if (ft_strncmp(str_flags[i], "-n", 2))
			return (i);
		tp = str_flags[i];
		j = 2;
		while (tp[j])
		{
			if (tp[j] != 'n')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
