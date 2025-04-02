/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:03:10 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/14 11:38:24 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_tab_str(char **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	nb_str_in_s(char const *s, char c)
{
	int	nb_str;
	int	i;

	i = 0;
	nb_str = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			nb_str++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb_str);
}

static char	*ft_create_str_split(char const *s, char c)
{
	int		len_new_s;
	char	*new_s;

	len_new_s = 0;
	while (s[len_new_s] != c && s[len_new_s])
		len_new_s++;
	new_s = malloc(sizeof(char) * (len_new_s + 1));
	if (new_s == NULL)
		return (NULL);
	len_new_s = 0;
	while (s[len_new_s] != c && s[len_new_s])
	{
		new_s[len_new_s] = s[len_new_s];
		len_new_s++;
	}
	new_s[len_new_s] = 0;
	return (new_s);
}

static char	**ft_create_tab_split(char const *s, char c, int nb_str)
{
	int		i;
	char	**tab_str;

	i = 0;
	tab_str = malloc(sizeof(char *) * (nb_str + 1));
	if (tab_str == NULL)
		return (NULL);
	nb_str = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			tab_str[nb_str] = ft_create_str_split(s + i, c);
			if (tab_str[nb_str] == NULL)
				return (ft_free_tab_str(tab_str, nb_str));
			nb_str++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	tab_str[nb_str] = NULL;
	return (tab_str);
}

char	**ft_split(char const *s, char c)
{
	int		nb_str;

	if (s == NULL)
		return (NULL);
	nb_str = nb_str_in_s(s, c);
	return (ft_create_tab_split(s, c, nb_str));
}
