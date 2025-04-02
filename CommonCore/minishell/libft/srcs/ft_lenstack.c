/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:34:26 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/16 21:37:57 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenstack(t_stack *a, t_stack *b)
{
	int	len;

	len = 0;
	while (a -> first)
	{
		ft_addstack(b, ft_delstack(a));
		len++;
	}
	while (b -> first)
		ft_addstack(a, ft_delstack(b));
	return (len);
}
