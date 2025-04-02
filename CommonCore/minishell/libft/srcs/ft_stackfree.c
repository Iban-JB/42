/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:44:25 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/06 14:08:08 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackfree(t_stack *stack)
{
	t_element	*element;
	t_element	*element_next;

	if (stack)
	{
		element_next = stack -> first;
		while (element_next)
		{
			element = element_next;
			element_next = element -> next;
			free(element);
		}
		free(stack);
	}
}
