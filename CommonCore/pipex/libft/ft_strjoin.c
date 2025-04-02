/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:14:20 by ibjean-b          #+#    #+#             */
/*   Updated: 2023/11/10 18:05:39 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	tot_len;
	size_t	len_s1;	
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 >= SIZE_MAX - len_s2)
	{
		join = malloc(0);
		if (!join)
			return (0);
		return (join);
	}
	tot_len = len_s1 + len_s2 + 1;
	join = malloc(tot_len);
	if (!join)
		return (0);
	ft_memcpy(join, s1, len_s1);
	ft_memcpy(join + len_s1, s2, len_s2 + 1);
	return (join);
}
