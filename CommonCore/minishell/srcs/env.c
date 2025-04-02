/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:12:59 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/11 15:39:35 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_value_var_env(char *name, char *value, \
t_minishell_info *minishell_info, t_bool is_child)
{
	int	id_var;
	int	len_name;
	int	len_value;

	len_name = ft_strlen(name);
	len_value = ft_strlen(value);
	id_var = find_id_var_env(minishell_info->env, name, len_name);
	if (id_var == -1)
		return (id_var);
	free_node(minishell_info->gr_coll, minishell_info->env[id_var], is_child);
	minishell_info->env[id_var] = \
	malloc_gr(minishell_info->gr_coll, (len_name + 2 + len_value) * \
	sizeof(char), false, is_child);
	if (!minishell_info->env[id_var])
		return (-2);
	ft_strcpy(minishell_info->env[id_var], name);
	minishell_info->env[id_var][len_name] = '=';
	ft_strcpy(minishell_info->env[id_var] + len_name + 1, value);
	minishell_info->env[id_var][len_name + len_value + 1] = 0;
	return (0);
}

int	find_id_var_env(char **env, char *name_var, int len_name_var)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], name_var, len_name_var) && \
		(int)ft_strlen(env[i]) > len_name_var && env[i][len_name_var] == '=')
			return (i);
	}
	return (-1);
}

char	**unset_var_env(char *name, char **env, \
t_minishell_info *minishell_info, t_bool is_child)
{
	int		i;
	int		id_var;
	char	**new_env;

	id_var = find_id_var_env(env, name, ft_strlen(name));
	if (id_var == -1)
		return (env);
	i = -1;
	new_env = malloc_gr(minishell_info->gr_coll, \
	sizeof(char *) * ft_len_tab_str(env), false, is_child);
	while (env[++i])
	{
		if (i < id_var)
			new_env[i] = env[i];
		else if (id_var < i)
			new_env[i - 1] = env[i];
		else
			free_node(minishell_info->gr_coll, env[i], is_child);
	}
	new_env[i - 1] = NULL;
	free_node(minishell_info->gr_coll, env, is_child);
	return (new_env);
}

int	ft_env(char **env, int fd)
{
	int	i;

	i = -1;
	while (env[++i])
		ft_dprintf(fd, "%s\n", env[i]);
	return (0);
}
