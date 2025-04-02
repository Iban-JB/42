/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:13:38 by ibjean-b          #+#    #+#             */
/*   Updated: 2023/11/10 17:57:08 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (0);
	memory = malloc(nmemb * size);
	if (!memory)
		return (0);
	ft_bzero(memory, nmemb * size);
	return (memory);
}
