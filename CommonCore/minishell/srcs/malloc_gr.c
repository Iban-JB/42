/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_gr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:28:52 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/10 21:55:25 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	*malloc_gr(t_gr_coll *garbage_collector, size_t size, \
t_bool here_doc, t_bool is_child)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		free_gr_all(garbage_collector, -1, is_child);
	node->here_doc = here_doc;
	node->content = malloc(size);
	if (!node->content)
	{
		free(node);
		free_gr_all(garbage_collector, 1, is_child);
	}
	node->next = garbage_collector->first_node;
	garbage_collector->first_node = node;
	garbage_collector->nb_node++;
	return (node->content);
}

void	free_gr_all(t_gr_coll *garbage_collector, \
int exit_value, t_bool is_child)
{
	t_node	*node;
	t_node	*node_next;

	node = garbage_collector->first_node;
	while (node)
	{
		node_next = node->next;
		if (is_child == false && node->here_doc == true)
			unlink((char *) node->content);
		free(node->content);
		free(node);
		node = node_next;
	}
	close_all_fd(garbage_collector);
	rl_clear_history();
	exit(exit_value);
}

void	free_node(t_gr_coll *garbage_collector, void *ptr, t_bool is_child)
{
	t_node	*node_tmp;
	t_node	*node_prec;

	node_tmp = garbage_collector->first_node;
	node_prec = NULL;
	while (node_tmp)
	{
		if (node_tmp->content == ptr)
		{
			if (!node_prec)
				garbage_collector->first_node = node_tmp->next;
			else
				node_prec->next = node_tmp->next;
			if (is_child == false && node_tmp->here_doc == true)
				unlink((char *) node_tmp->content);
			free(node_tmp->content);
			return (free(node_tmp));
		}
		node_prec = node_tmp;
		node_tmp = node_tmp->next;
	}
}

int	fork_gr(t_gr_coll *gr_coll)
{
	int	fork_return;

	fork_return = fork();
	if (fork_return == -1)
		free_gr_all(gr_coll, 1, false);
	return (fork_return);
}
