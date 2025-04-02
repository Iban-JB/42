/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:48:15 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/08 11:48:15 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_change_value_env(t_minishell_info *minishell_info, \
t_bool is_child, int i, char *name);

int	ft_export(t_minishell_info *minishell_info, char **name, t_bool is_child)
{
	int	i;
	int	j;

	j = 0;
	if (!name[1])
		return (ft_dprintf(STDERR_FILENO, "%s%s: name[=word]\n", MINISHELL, \
		EXPORT), 1);
	while (name[++j])
	{
		if (ft_isdigit(*(name[j])) || *(name[j]) == '=')
			return (ft_dprintf(STDERR_FILENO, "%s%s `%s': %s\n", \
			MINISHELL, EXPORT, name[j], INVALID_IDENTIFIER), 1);
		i = -1;
		while (name[j][++i] && name[j][i] != '=')
			if (!ft_isalnum((int) name[j][i]) && name[j][i] != '_')
				return (ft_dprintf(STDERR_FILENO, "%s%s: `%s': %s\n", \
				MINISHELL, EXPORT, name[j], INVALID_IDENTIFIER), 1);
		if (name[j][i] == '=')
			add_change_value_env(minishell_info, is_child, i, name[j]);
	}
	return (0);
}

static void	add_change_value_env(t_minishell_info *minishell_info, \
t_bool is_child, int i, char *name)
{
	int	indice_var_env;

	indice_var_env = find_id_var_env(minishell_info->env, name, i);
	if (indice_var_env == -1)
		minishell_info->env = add_str_double_tab(minishell_info->env, \
				strdup_gr(name, minishell_info->gr_coll, \
				is_child), minishell_info->gr_coll, is_child);
	else
	{
		free_node(minishell_info->gr_coll, \
				minishell_info->env[indice_var_env], is_child);
		minishell_info->env[indice_var_env] = \
				strdup_gr(name, minishell_info->gr_coll, is_child);
	}
}
