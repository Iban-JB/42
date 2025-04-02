/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:50:56 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/25 15:46:51 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_rotate_b_to_a(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = try_rrarrb_a(a, b, b->nbr);
	while (tmp)
	{
		if (i > try_rarb_a(a, b, tmp->nbr))
			i = try_rarb_a(a, b, tmp->nbr);
		if (i > try_rrarrb_a(a, b, tmp->nbr))
			i = try_rrarrb_a(a, b, tmp->nbr);
		if (i > try_rarrb_a(a, b, tmp->nbr))
			i = try_rarrb_a(a, b, tmp->nbr);
		if (i > try_rrarb_a(a, b, tmp->nbr))
			i = try_rrarb_a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	best_rotate_a_to_b(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = try_rrarrb(a, b, a->nbr);
	while (tmp)
	{
		if (i > try_rarb(a, b, tmp->nbr))
			i = try_rarb(a, b, tmp->nbr);
		if (i > try_rrarrb(a, b, tmp->nbr))
			i = try_rrarrb(a, b, tmp->nbr);
		if (i > try_rarrb(a, b, tmp->nbr))
			i = try_rarrb(a, b, tmp->nbr);
		if (i > try_rrarb(a, b, tmp->nbr))
			i = try_rrarb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
