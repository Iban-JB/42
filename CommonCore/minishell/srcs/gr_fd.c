/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 01:10:32 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/11 15:37:37 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

int	open_gr(t_gr_coll *gr_coll, int fd, t_bool is_child)
{
	t_node_int	*node_int;

	if (fd != -1)
	{
		node_int = malloc(sizeof(t_node_int));
		if (!node_int)
			free_gr_all(gr_coll, 1, is_child);
		node_int->fd = fd;
		node_int->next = gr_coll->fr_node_int;
		gr_coll->fr_node_int = node_int;
	}
	return (fd);
}

void	close_gr(t_gr_coll *gr_coll, t_bool is_child, int fd)
{
	t_node_int	*prec_node_int;
	t_node_int	*act_node_int;

	if (close(fd) == -1)
		free_gr_all(gr_coll, 1, is_child);
	prec_node_int = NULL;
	act_node_int = gr_coll->fr_node_int;
	while (act_node_int)
	{
		if (act_node_int->fd == fd)
		{
			if (prec_node_int == NULL)
				gr_coll->fr_node_int = act_node_int->next;
			else
				prec_node_int->next = act_node_int->next;
			return (free(act_node_int));
		}
		prec_node_int = act_node_int;
		act_node_int = act_node_int->next;
	}
}

void	close_all_fd(t_gr_coll *gr_coll)
{
	t_node_int	*node_act;
	t_node_int	*node_next;

	node_act = gr_coll->fr_node_int;
	while (node_act)
	{
		node_next = node_act->next;
		close(node_act->fd);
		free(node_act);
		node_act = node_next;
	}
}

void	pipe_gr(int *fd, t_gr_coll *gr_coll, t_bool is_child)
{
	if (pipe(fd) == -1)
		free_gr_all(gr_coll, 1, is_child);
	open_gr(gr_coll, fd[0], is_child);
	open_gr(gr_coll, fd[1], is_child);
}

void	dup2_gr(t_gr_coll *gr_coll, int old, int new, t_bool is_child)
{
	if (dup2(old, new) == -1)
		free_gr_all(gr_coll, 1, is_child);
}
