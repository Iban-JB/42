/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:44:26 by ibjean-b          #+#    #+#             */
/*   Updated: 2023/11/10 18:07:10 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	tot_len;

	if (ft_strlen(s) <= start)
	{
		sub = malloc(1);
		if (!sub)
			return (0);
		sub[0] = 0;
		return (sub);
	}
	if (ft_strlen(s + start) < len)
		tot_len = ft_strlen(s + start) + 1;
	else
		tot_len = len + 1;
	sub = malloc(tot_len);
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, tot_len);
	return (sub);
}
