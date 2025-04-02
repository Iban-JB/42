/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:15:17 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/13 20:34:05 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_value;

	if (lst == NULL || new == NULL)
		return ;
	lst_value = *lst;
	if (*lst)
	{
		while (lst_value -> next)
			lst_value = lst_value -> next;
		lst_value -> next = new;
	}
	else
		*lst = new;
}
