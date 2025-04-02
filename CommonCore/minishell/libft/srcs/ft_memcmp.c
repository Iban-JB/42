/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:15:55 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/08 16:44:52 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*datas1;
	char	*datas2;
	size_t	i;

	datas1 = (char *)s1;
	datas2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (datas1[i] != datas2[i])
			return ((unsigned char)datas1[i] - (unsigned char)datas2[i]);
		i++;
	}
	return (0);
}
