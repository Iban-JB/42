/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:34:43 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/09 17:49:04 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*memory;
	char	*data;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	data = (char *)src;
	memory = (char *)dest;
	while (i < n)
	{
		memory[i] = data[i];
		i++;
	}
	return (memory);
}
