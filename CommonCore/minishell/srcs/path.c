/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 07:22:41 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/07 18:07:45 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(char **env)
{
	int		i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (DEFAULT_PATH);
}

t_bool	try_to_access(char *path_cmd, char *name)
{
	struct stat	path;

	stat(path_cmd, &path);
	if (!(access(path_cmd, F_OK)) && \
	!(access(path_cmd, X_OK)) && S_ISREG(path.st_mode))
		return (true);
	else if (!(access(path_cmd, F_OK)) && access(path_cmd, X_OK))
		fprintf(stderr, "%s%s%s\n", MINISHELL, name, NO_PERMS);
	return (false);
}

char	*create_new_path(t_gr_coll *gr_coll, char *new_path, char *name)
{
	char	*tp;
	char	*new_path_cmd;

	tp = ft_strjoin_gr(gr_coll, new_path, "/", true);
	new_path_cmd = ft_strjoin_gr(gr_coll, tp, name, true);
	free_node(gr_coll, tp, true);
	if (!new_path_cmd)
		return (0);
	return (new_path_cmd);
}

char	*find_path_command(t_minishell_info *shell_info, char *name)
{
	char	**all_path;
	char	*path_cmd;
	int		i;

	all_path = ft_split_gr(shell_info->gr_coll, get_path(shell_info->env), ':');
	i = -1;
	while (all_path && all_path[++i])
	{
		path_cmd = create_new_path(shell_info->gr_coll, all_path[i], name);
		if (try_to_access(path_cmd, name))
		{
			free_tab_str(all_path, -1, shell_info->gr_coll, true);
			return (path_cmd);
		}
		free_node(shell_info->gr_coll, path_cmd, true);
	}
	fprintf(stderr, "%s%s%s\n", MINISHELL, name, NO_FOUND);
	return (NULL);
}
