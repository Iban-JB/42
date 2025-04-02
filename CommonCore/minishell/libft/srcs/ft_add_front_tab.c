/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_front_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:54:38 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/19 14:38:12 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_front_tab(t_tab_stack *stack_add, int value)
{
	int	i;
	int	*tab;

	stack_add -> len = stack_add -> len + 1;
	i = stack_add -> len;
	tab = stack_add -> tab_stack;
	while (--i >= 1)
		tab[i] = tab[i - 1];
	tab[0] = value;
}
