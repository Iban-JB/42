/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_elmnt_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:45:08 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/16 19:18:59 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_crt_elmnt_stack(t_stack *stack, int value)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element)
		return (false);
	new_element -> value = value;
	new_element -> rank = -1;
	ft_addstack(stack, new_element);
	return (true);
}
