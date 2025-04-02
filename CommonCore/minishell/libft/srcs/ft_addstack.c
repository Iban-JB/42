/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:09:36 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/14 18:13:31 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addstack(t_stack *stack, t_element *new_element)
{
	if (!stack || !new_element)
		return ;
	new_element -> next = stack -> first;
	stack -> first = new_element;
}
