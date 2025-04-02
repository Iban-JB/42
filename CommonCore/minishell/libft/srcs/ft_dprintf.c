/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:18:25 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/05 19:00:07 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_p(va_list *args, int fd)
{
	int						nb_char;
	unsigned long long int	value;

	value = va_arg(*args, unsigned long long int);
	if (!value)
		return (ft_putstr_fd("(nil)", fd));
	if (ft_putstr_fd("0x", fd) < 0)
		return (-1);
	nb_char = ft_putnbr_base_long_fd(value, "0123456789abcdef", 16, fd);
	if (nb_char < 0)
		return (-1);
	return (nb_char + 2);
}

static int	ft_print_other(const char c, int fd)
{
	if (ft_putchar_fd('%', fd) < 0)
		return (0);
	if (ft_putchar_fd(c, fd) < 0)
		return (0);
	return (2);
}

static int	ft_print_type(const char c, va_list *args, int fd)
{
	if (!c)
		return (-1);
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), fd));
	else if (c == 'c')
		return (ft_putchar_fd((char)va_arg(*args, int), fd));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(*args, char *), fd));
	else if (c == 'x')
		return (ft_putnbr_base_long_fd(va_arg(*args, unsigned int), \
		"0123456789abcdef", 16, fd));
	else if (c == 'X')
		return (ft_putnbr_base_long_fd(va_arg(*args, unsigned int), \
		"0123456789ABCDEF", 16, fd));
	else if (c == 'u')
		return (ft_putnbr_base_long_fd(va_arg(*args, unsigned int), \
		"0123456789", 10, fd));
	else if (c == 'p')
		return (ft_print_p(args, fd));
	else if (c == '%')
		return (ft_putchar_fd('%', fd));
	return (ft_print_other(c, fd));
}

static int	ft_read_format(const char *format, va_list *args, int fd)
{
	int		i;
	int		nb_write;
	int		write;

	i = -1;
	nb_write = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			write = ft_print_type(format[i + 1], args, fd);
			if (write < 0)
				return (-1);
			nb_write += write;
			i ++;
		}
		else
		{
			write = ft_putchar_fd(format[i], fd);
			if (write < 0)
				return (-1);
			nb_write += 1;
		}
	}
	return (nb_write);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		nb_write;

	if (!format)
		return (-1);
	va_start (args, format);
	nb_write = ft_read_format(format, &args, fd);
	va_end (args);
	return (nb_write);
}
