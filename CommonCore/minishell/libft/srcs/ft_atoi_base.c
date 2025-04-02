/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:20:24 by rperrot           #+#    #+#             */
/*   Updated: 2023/07/26 11:53:40 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	value_atoi(char *str, int i, char *base, int length_base)
{
	int	value;
	int	is_in_base;
	int	i_base;

	value = 0;
	is_in_base = 1;
	while (is_in_base && str[i])
	{
		i_base = 0;
		while (i_base < length_base && str[i] != base[i_base])
			i_base++;
		if (i_base == length_base)
			is_in_base = 0;
		else
		{
			value *= length_base;
			value += i_base;
			i++;
		}
	}
	return (value);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	value;
	int	signe;

	signe = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe++;
		i++;
	}
	value = value_atoi(str, i, base, ft_strlen(base));
	if (signe % 2)
		value *= -1;
	return (value);
}
