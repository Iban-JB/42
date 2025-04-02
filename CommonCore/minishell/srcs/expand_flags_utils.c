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

void	next_space(int *i, char const *s)
{
	while (s[*i] == ' ' && s[*i])
	{
		*i = *i + 1;
		if ((s[*i] == -1 && s[*i + 1] == -1) || (s[*i] == -2 && \
s[*i + 1] == -2))
			*i = *i + 2;
	}
}

void	find_len_string(int *i, int *len_new_s, const char *s, char *new_s)
{
	char	c;

	while (s[*i] != ' ' && s[*i])
	{
		if (s[*i] == -1 || s[*i] == -2)
		{
			c = s[*i];
			*i = *i + 1;
			while (s[*i] != c && s[*i])
			{
				if (new_s)
					new_s[*len_new_s] = s[*i];
				*len_new_s = *len_new_s + 1;
				*i = *i + 1;
			}
		}
		else
		{
			if (new_s)
				new_s[*len_new_s] = s[*i];
			*len_new_s = *len_new_s + 1;
		}
		*i = *i + 1;
	}
}

void	next_string(int *i, char const *s)
{
	char	c;

	while (s[*i] != ' ' && s[*i])
	{
		if (s[*i] == -1 || s[*i] == -2)
		{
			c = s[*i];
			*i = *i + 1;
			while (s[*i] != c && s[*i])
				*i = *i + 1;
		}
		*i = *i + 1;
	}
}
