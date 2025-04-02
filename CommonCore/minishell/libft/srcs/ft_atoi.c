/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:35:55 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/06 15:00:50 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	value_atoi(const char *str, int i, int signe)
{
	long long int	value;

	value = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value *= 10;
		value += str[i] - '0';
		if (value < 0)
		{
			if (signe)
				return (0);
			return (-1);
		}
		i++;
	}
	if (signe)
		value *= -1;
	return ((int)value);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;

	signe = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe++;
		i++;
	}
	return (value_atoi(str, i, signe));
}

t_bool	char_is_number(char *str)
{
	int	i;

	i = -1;
	if (str[i + 1] == '+' || str[i + 1] == '-')
		i++;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}
