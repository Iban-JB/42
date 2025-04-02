/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:53:57 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/13 19:43:12 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*data;

	data = (char *)s;
	i = 0;
	while (i < n)
	{
		if (data[i] == (char)c)
			return ((void *)&data[i]);
		i++;
	}
	return (NULL);
}
