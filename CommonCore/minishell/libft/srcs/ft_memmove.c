/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:09:04 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/14 17:48:31 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*memory;
	char	*data;

	data = (char *)src;
	memory = (char *)dest;
	if (src == dest)
		return (memory);
	if (src > dest)
	{
		i = 0;
		while (i < n)
		{
			memory[i] = data[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			memory[n] = data[n];
	}
	return (memory);
}
