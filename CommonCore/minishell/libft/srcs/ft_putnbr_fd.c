/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:04:57 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/05 18:59:49 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	len;
	int	signe;

	signe = 0;
	len = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		signe = 1;
		n = -n;
		if (ft_putchar_fd('-', fd) < 0)
			return (0);
	}
	if (n >= 10)
		len = ft_putnbr_fd(n / 10, fd);
	if (len == -1)
		return (-1);
	if (ft_putchar_fd(n % 10 + '0', fd) < 0)
		return (-1);
	if (signe)
		len++;
	return (len + 1);
}
