/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:55:27 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/14 11:37:26 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstclearnull(t_list **lst, void (*del)(void*))
{
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_next;
	t_list	*lst_start;

	if (lst == NULL || del == NULL || f == NULL)
		return (NULL);
	lst_start = malloc(sizeof(t_list));
	if (lst_start == NULL || del == NULL || f == NULL)
		return (NULL);
	lst_next = lst_start;
	while (lst)
	{
		lst_next -> content = f(lst -> content);
		lst = lst -> next;
		if (lst)
		{
			lst_next -> next = malloc(sizeof(t_list));
			if (lst_next -> next == NULL)
				return (ft_lstclearnull(&lst_start, del));
			lst_next = lst_next -> next;
		}
	}
	lst_next -> next = NULL;
	return (lst_start);
}
