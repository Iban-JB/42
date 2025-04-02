/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_double_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:45:49 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 16:47:52 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_str_double_tab(char **argv, char *name,
t_gr_coll *gr_coll, t_bool is_child)
{
	int		size_argv;
	char	**new_argv;

	if (!name)
		return (argv);
	size_argv = 0;
	while (argv[size_argv])
		size_argv++;
	new_argv = malloc_gr(gr_coll, sizeof(char *) * (size_argv + 2), \
	false, is_child);
	size_argv = -1;
	while (argv[++size_argv])
		new_argv[size_argv] = argv[size_argv];
	free_node(gr_coll, argv, is_child);
	new_argv[size_argv] = name;
	new_argv[size_argv + 1] = NULL;
	return (new_argv);
}

void	free_tab_str(char **tab, int size, t_gr_coll *gr_coll, t_bool is_child)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	if (size == -1)
	{
		while (tab[++i])
			free_node(gr_coll, tab[i], is_child);
	}
	else
	{
		while (++i < size)
			free_node(gr_coll, tab[i], is_child);
	}
	free_node(gr_coll, tab, is_child);
}
