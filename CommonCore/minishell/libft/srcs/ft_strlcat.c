/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:48:45 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/09 17:11:04 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	i;

	if ((dest == NULL || src == NULL) && size == 0)
		return (0);
	i = 0;
	j = 0;
	while (dest[j] && j < size)
		j++;
	if (dest[j])
		return (j + ft_strlen(src));
	while (src[i] && (i + j + 1) < (size))
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = 0;
	return (j + ft_strlen(src));
}
