/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:25:40 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/14 17:55:14 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		len_s;
	char		*new_src;
	long int	nb_char_new_src;
	long int	i;

	len_s = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start + len > len_s)
		nb_char_new_src = len_s - start;
	else
		nb_char_new_src = len;
	if (nb_char_new_src <= 0)
		nb_char_new_src = 0;
	new_src = malloc(sizeof(char) * (nb_char_new_src + 1));
	if (new_src == NULL)
		return (NULL);
	i = -1;
	while (++i < nb_char_new_src)
		new_src[i] = s[i + start];
	new_src[i] = 0;
	return (new_src);
}
