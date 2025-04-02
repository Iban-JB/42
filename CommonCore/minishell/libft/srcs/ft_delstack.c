/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:27:41 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/14 13:06:40 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_delstack(t_stack *stack)
{
	t_element	*del_elmt;

	del_elmt = stack -> first;
	if (del_elmt)
		stack -> first = stack -> first -> next;
	return (del_elmt);
}
