/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:23:50 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/14 17:52:10 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cp_s;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	i = 0;
	cp_s = malloc(sizeof(char) * len_s + 1);
	if (cp_s == NULL)
		return (NULL);
	while (i < len_s)
	{
		cp_s[i] = s[i];
		i++;
	}
	cp_s[i] = s[i];
	return (cp_s);
}
