/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:48:04 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/07 17:50:51 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_gr(t_gr_coll *gr_coll, char const *s1, \
char const *s2, t_bool is_child)
{
	char	*s_join;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	s_join = malloc_gr(gr_coll, sizeof(char) * (len + 1), false, is_child);
	while (*s1)
		*s_join++ = *s1++;
	while (*s2)
		*s_join++ = *s2++;
	*s_join = 0;
	return (s_join - len);
}
