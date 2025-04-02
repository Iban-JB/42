/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:36:24 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/11 16:11:13 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	add_node(void *ptr, t_gr_coll *gr_coll)
{
	t_node	*node;

	if (ptr)
	{
		node = malloc(sizeof(t_node));
		if (!node)
			free_gr_all(gr_coll, -1, false);
		node->here_doc = false;
		node->content = ptr;
		node->next = gr_coll->first_node;
		gr_coll->first_node = node;
		gr_coll->nb_node++;
	}
}
