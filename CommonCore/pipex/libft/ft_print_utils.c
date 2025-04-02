/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:27:06 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/07 17:28:01 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_print_char(char c, int *count)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*count)++;
	return (0);
}

int	ft_print_string(char *s, int *count)
{
	int	len;

	if (!s)
		return (ft_print_string("(null)", count));
	else
	{
		len = ft_strlen(s);
		if (len < 0 || (write(1, s, len) == -1))
			return (-1);
		(*count) += len;
	}
	return (0);
}

int	ft_print_number_base(long n, char *base, int *count)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (n < 0)
	{
		ft_print_char('-', count);
		n *= -1;
	}
	if (n >= len_base)
	{
		ft_print_number_base(n / len_base, base, count);
		ft_print_char(base[n % len_base], count);
	}
	if (n >= 0 && n < len_base)
		return (ft_print_char(base[n], count));
	return (0);
}

int	ft_print_adress(unsigned long long addr, char *base, int *count)
{
	unsigned long long	len_base;

	if (!addr)
		return (ft_print_string("(nil)", count));
	ft_print_string("0x", count);
	len_base = ft_strlen(base);
	if (addr >= len_base)
	{
		ft_print_number_base(addr / len_base, base, count);
		ft_print_char(base[addr % len_base], count);
	}
	if (addr > 0 && addr < len_base)
		return (ft_print_char(base[addr], count));
	return (0);
}
