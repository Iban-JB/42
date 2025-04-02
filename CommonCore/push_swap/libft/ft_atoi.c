/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:54:57 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/04/02 14:56:21 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_get_num(int sign, const char *str, size_t i)
{
	long	result;

	result = 0;
	while (ft_isdigit(str[i]))
	{
		if (result != (result * 10 + (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;
	size_t	i;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	res = ft_get_num(sign, nptr, i);
	return (res * sign);
}
