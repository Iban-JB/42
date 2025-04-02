/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:06:25 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/10 21:06:07 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include "minishell.h"

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	t_bool			here_doc;
}	t_node;

typedef struct s_node_int
{
	int					fd;
	struct s_node_int	*next;
}	t_node_int;

typedef struct s_gr_coll
{
	int			nb_node;
	t_node		*first_node;
	t_node_int	*fr_node_int;
	char		*line;
}	t_gr_coll;

void	*malloc_gr(t_gr_coll *garbage_collector, size_t size, \
t_bool here_doc, t_bool is_child);
void	free_gr_all(t_gr_coll *garbage_collector, int exit_value, \
t_bool is_child);
void	free_node(t_gr_coll *garbage_collector, void *ptr, t_bool is_child);
void	close_all_fd(t_gr_coll *gr_coll);
void	close_gr(t_gr_coll *gr_coll, t_bool is_child, int fd);
int		open_gr(t_gr_coll *gr_coll, int fd, t_bool is_child);
void	pipe_gr(int *fd, t_gr_coll *gr_coll, t_bool is_child);
int		fork_gr(t_gr_coll *gr_coll);
void	dup2_gr(t_gr_coll *gr_coll, int old, int new, t_bool is_child);
void	add_node(void *ptr, t_gr_coll *gr_coll);
#endif
