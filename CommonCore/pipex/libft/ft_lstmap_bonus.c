/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:24:58 by ibjean-b          #+#    #+#             */
/*   Updated: 2023/11/13 13:55:12 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*begin;
	void	*tp;

	new_lst = 0;
	begin = new_lst;
	while (lst)
	{
		tp = f(lst->content);
		if (!tp)
		{
			ft_lstclear(&begin, del);
			return (0);
		}
		new_lst = ft_lstnew(tp);
		if (!new_lst)
		{
			ft_lstclear(&begin, del);
			del(tp);
			return (0);
		}
		ft_lstadd_back(&begin, new_lst);
		lst = lst->next;
	}
	return (begin);
}
