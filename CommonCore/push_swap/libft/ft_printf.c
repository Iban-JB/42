/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:12:22 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/01/10 11:02:31 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_print_char(char c, int *count);
int	ft_print_string(char *s, int *count);
int	ft_print_number_base(long n, char *base, int *count);
int	ft_print_adress(unsigned long long addr, char *base, int *count);

int	ft_get_type(char c, va_list vl, int *count)
{
	if (c == 'c')
		return (ft_print_char(va_arg(vl, int), count));
	else if (c == 's')
		return (ft_print_string(va_arg(vl, char *), count));
	else if (c == 'p')
		return (ft_print_adress \
		(va_arg(vl, unsigned long long), "0123456789abcdef", count));
	else if (c == 'd' || c == 'i')
		return (ft_print_number_base \
		(va_arg(vl, int), "0123456789", count));
	else if (c == 'u')
		return (ft_print_number_base \
		(va_arg(vl, unsigned int), "0123456789", count));
	else if (c == 'x')
		return (ft_print_number_base \
		(va_arg(vl, unsigned int), "0123456789abcdef", count));
	else if (c == 'X')
		return (ft_print_number_base \
		(va_arg(vl, unsigned int), "0123456789ABCDEF", count));
	else if (c == '%')
		return (ft_print_char('%', count));
	return (ft_print_char(c, count));
}

int	ft_print_format(char *format, va_list vl, int *count)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 0)
			return (-1);
		else if (*format == '%' && *(format + 1))
		{
			if (ft_get_type(*(format + 1), vl, count) == -1)
				return (-1);
			format += 2;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			format++;
			(*count)++;
		}
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	vl;

	if (!format)
		return (-1);
	count = 0;
	va_start(vl, format);
	if (ft_print_format((char *)format, vl, &count) == -1)
	{
		va_end(vl);
		return (-1);
	}
	va_end(vl);
	return (count);
}
