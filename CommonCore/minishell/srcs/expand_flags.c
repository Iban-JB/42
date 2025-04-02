/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_gr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:36:30 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/07 17:41:08 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	nb_str_in_s(char const *s)
{
	int		nb_str;
	int		i;

	i = 0;
	nb_str = 0;
	while (s[i])
	{
		next_space(&i, s);
		if (s[i] != ' ' && s[i])
			nb_str++;
		next_string(&i, s);
	}
	return (nb_str);
}

static char	*ft_create_str_split(t_gr_coll *gr_coll, char const *s)
{
	int		len_new_s;
	int		i;
	char	*new_s;

	len_new_s = 0;
	i = 0;
	find_len_string(&i, &len_new_s, s, NULL);
	new_s = malloc_gr(gr_coll, sizeof(char) * (len_new_s + 1), false, false);
	len_new_s = 0;
	i = 0;
	find_len_string(&i, &len_new_s, s, new_s);
	new_s[len_new_s] = 0;
	return (new_s);
}

static char	**ft_create_tab_split(t_gr_coll *gr_coll, char const *s, int nb_str)
{
	int		i;
	char	**tab_str;

	i = 0;
	tab_str = malloc_gr(gr_coll, sizeof(char *) * (nb_str + 1), false, false);
	nb_str = 0;
	while (s[i])
	{
		next_space(&i, s);
		if (s[i] != ' ' && s[i])
		{
			tab_str[nb_str] = ft_create_str_split(gr_coll, s + i);
			nb_str++;
		}
		next_string(&i, s);
	}
	tab_str[nb_str] = NULL;
	return (tab_str);
}

char	**ft_split_pattern(t_gr_coll *gr_coll, char const *s)
{
	int		nb_str;

	if (s == NULL)
		return (NULL);
	nb_str = nb_str_in_s(s);
	return (ft_create_tab_split(gr_coll, s, nb_str));
}
