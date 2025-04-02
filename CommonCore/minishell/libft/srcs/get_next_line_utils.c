/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:58:09 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/24 15:11:12 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_line(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin_line(char	*last, char *buffer, size_t	n)
{
	char	*s_join;
	size_t	len;
	size_t	i;

	if (!buffer || !(*buffer))
		return (NULL);
	if (n == 0)
		n = ft_strlen_line(buffer);
	len = ft_strlen_line(last) + n;
	s_join = malloc(sizeof(char) * (len + 1));
	if (!s_join)
		return (ft_free_line(last, NULL));
	if (last)
	{
		while (*last)
			*s_join++ = *last++;
	}
	i = -1;
	while (++i < n)
		*s_join++ = buffer[i];
	*s_join = 0;
	if (last)
		free(last - len + n);
	buffer[0] = 0;
	return (s_join - len);
}

size_t	ft_findnewline(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		return (++i);
	return (i);
}

size_t	ft_find_jump(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

void	ft_memzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}
