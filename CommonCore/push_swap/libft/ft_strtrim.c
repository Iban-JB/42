/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:09:50 by ibjean-b          #+#    #+#             */
/*   Updated: 2023/11/10 18:07:05 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_count_len(char const *s1, char const *set)
{
	size_t	len;
	size_t	end;
	size_t	nb_tot;

	nb_tot = 0;
	len = ft_strlen(s1);
	while (s1[nb_tot] && ft_in_set(set, s1[nb_tot]))
		nb_tot++;
	end = len;
	if (nb_tot < len)
	{
		while (end > 0 && s1[end - 1] && ft_in_set(set, s1[end - 1]))
		{
			end--;
			nb_tot++;
		}
	}
	return (len - nb_tot);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;
	size_t	start;

	len = ft_count_len(s1, set);
	trim = malloc(len + 1);
	if (!trim)
		return (0);
	start = 0;
	while (s1[start] && ft_in_set(set, s1[start]) && len > 0)
		start++;
	ft_memcpy(trim, s1 + start, len);
	trim[len] = 0;
	return (trim);
}
