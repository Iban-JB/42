/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:49:12 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/15 15:16:38 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_new_s(const char *s1, int start, int end)
{
	int		length_new_s;
	char	*new_s;
	int		i;

	length_new_s = end + 1 - start;
	if (length_new_s < 0)
		length_new_s = 0;
	new_s = malloc(sizeof(char) * (length_new_s + 1));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	if (length_new_s)
	{
		i = -1;
		while (start + ++i != end + 1)
			new_s[i] = s1[i + start];
	}
	new_s[i] = 0;
	return (new_s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, (int)s1[start]))
		start++;
	while (ft_strchr(set, (int)s1[end]))
		end--;
	return (ft_create_new_s(s1, start, end));
}
