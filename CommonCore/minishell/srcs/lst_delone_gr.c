/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delone_gr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:57:46 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 14:22:34 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstdelone_gr(t_list *lst, void (*del)(void*, \
t_gr_coll*, t_bool), t_gr_coll *gr_coll, t_bool is_child)
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content, gr_coll, is_child);
	free_node(gr_coll, lst, is_child);
}
