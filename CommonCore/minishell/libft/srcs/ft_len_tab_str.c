/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_tab_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:53:41 by rperrot           #+#    #+#             */
/*   Updated: 2024/05/27 14:53:41 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len_tab_str(char **tab)
{
	size_t	len;

	if (!tab)
		return (0);
	len = 0;
	while (tab[len])
		len++;
	return (len);
}
