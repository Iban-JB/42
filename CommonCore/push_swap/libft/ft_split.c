/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:32:11 by ibjean-b          #+#    #+#             */
/*   Updated: 2023/11/10 18:04:37 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	nbw;

	nbw = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nbw++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (nbw);
}

static int	ft_free_all(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

static int	ft_complete_split(char const *s, char c, char **split)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] != c)
		{
			start = end;
			while (s[end] && s[end] != c)
				end++;
			split[i] = ft_calloc(end - start + 1, sizeof(char));
			if (!split[i])
				return (ft_free_all(split));
			ft_strlcpy(split[i], s + start, end - start + 1);
			i++;
		}
		while (s[end] && s[end] == c)
			end++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	nbw;

	nbw = ft_count_word(s, c);
	split = ft_calloc(nbw + 1, sizeof(char *));
	if (!split)
		return (0);
	if (ft_complete_split(s, c, split) == 0)
		return (0);
	return (split);
}
