/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:44:16 by ibjean-b          #+#    #+#             */
/*   Updated: 2023/11/10 18:03:00 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tp;

	i = 0;
	tp = (unsigned char *)s;
	while (i < n)
	{
		tp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
