/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:45:23 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/14 11:37:03 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_number(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	long_n;
	int			i;
	char		*s;

	long_n = (long int)n;
	s = malloc(sizeof(char) * (ft_len_number(n) + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	if (long_n < 0)
	{
		long_n *= -1;
		s[0] = '-';
	}
	i += ft_len_number(n);
	s[i] = 0;
	if (long_n == 0)
		s[i - 1] = '0';
	while (long_n != 0)
	{
		i--;
		s[i] = long_n % 10 + '0';
		long_n /= 10;
	}
	return (s);
}
