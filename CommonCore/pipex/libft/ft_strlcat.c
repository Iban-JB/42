/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:34:37 by ibjean-b          #+#    #+#             */
/*   Updated: 2023/11/10 16:17:32 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = 0;
	len_src = 0;
	while (dst[len_dest] && len_dest < size)
		len_dest++;
	while (src[len_src])
		len_src++;
	while (src[i] && len_dest + i + 1 < size)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	if (len_dest < size)
		dst[len_dest + i] = '\0';
	return (len_src + len_dest);
}
