/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:59:32 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/14 17:38:58 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmem, size_t size)
{
	void	*memory;

	if (nmem == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmem)
		return (NULL);
	memory = malloc(nmem * size);
	if (memory == NULL)
		return (NULL);
	ft_bzero(memory, size * nmem);
	return (memory);
}
