/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:51:24 by ibjean-b          #+#    #+#             */
/*   Updated: 2023/11/13 09:53:07 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tp;

	while (lst && (*lst))
	{
		tp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tp;
	}
	(*lst) = NULL;
}
