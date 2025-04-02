/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_gr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:36:47 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 14:16:03 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_gr(t_list **lst, void (*del)(void*, \
t_gr_coll*, t_bool), t_gr_coll *gr_coll, t_bool is_child)
{
	t_list	*lst_next;

	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		lst_next = (*lst)-> next;
		ft_lstdelone_gr(*lst, del, gr_coll, is_child);
		*lst = lst_next;
	}
	*lst = NULL;
}
