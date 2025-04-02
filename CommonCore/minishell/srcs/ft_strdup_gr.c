/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_gr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:32:29 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 15:57:41 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strdup_gr(const char *s, t_gr_coll *gr_coll, t_bool is_child)
{
	char	*cp_s;
	size_t	i;
	size_t	len_s;

	if (!s)
		free_gr_all(gr_coll, 1, false);
	len_s = ft_strlen(s);
	i = 0;
	cp_s = malloc_gr(gr_coll, sizeof(char) * len_s + 1, false, is_child);
	while (i < len_s)
	{
		cp_s[i] = s[i];
		i++;
	}
	cp_s[i] = s[i];
	return (cp_s);
}
