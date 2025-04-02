/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_front_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:12:12 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/19 14:44:17 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_del_front_tab(t_tab_stack *stack_del)
{
	int	del_value;
	int	i;
	int	*tab;
	int	len;

	len = stack_del -> len;
	tab = stack_del -> tab_stack;
	del_value = *tab;
	i = -1;
	while (++i < len - 1)
		tab[i] = tab[i + 1];
	stack_del -> len = stack_del -> len - 1;
	return (del_value);
}
