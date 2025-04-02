/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:04:11 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/21 14:21:25 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_join;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	s_join = malloc(sizeof(char) * (len + 1));
	if (!s_join)
		return (NULL);
	while (*s1)
		*s_join++ = *s1++;
	while (*s2)
		*s_join++ = *s2++;
	*s_join = 0;
	return (s_join - len);
}

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*s_join;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	s_join = malloc(sizeof(char) * (len + 1));
	if (!s_join)
		return (NULL);
	while (*s1)
		*s_join++ = *s1++;
	while (*s2)
		*s_join++ = *s2++;
	while (*s3)
		*s_join++ = *s3++;
	*s_join = 0;
	return (s_join - len);
}
