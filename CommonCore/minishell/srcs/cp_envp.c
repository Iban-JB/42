/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:17:19 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 15:59:50 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cp_envp(char **envp, t_gr_coll *gr_coll)
{
	int		len;
	char	**new_env;
	int		indice_var_env;

	indice_var_env = find_id_var_env(envp, "SHLVL", 5);
	len = 0;
	while (envp[len])
		len++;
	len += indice_var_env == -1;
	new_env = malloc_gr(gr_coll, sizeof (char *) * (len + 1), false, false);
	len = -1;
	while (envp[++len])
	{
		if (len != -1)
			new_env[len] = strdup_gr(envp[len], gr_coll, false);
	}
	if (indice_var_env == -1)
		new_env[len++] = strdup_gr("SHLVL=0", gr_coll, false);
	new_env[len] = NULL;
	return (new_env);
}
