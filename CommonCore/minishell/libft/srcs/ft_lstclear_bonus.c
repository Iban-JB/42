/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:36:48 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/13 17:56:49 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_next;

	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		lst_next = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = lst_next;
	}
	*lst = NULL;
}
