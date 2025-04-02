/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:59:01 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/25 15:48:17 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	try_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_spot_a(a, c);
	if (i < find_index(b, c))
		i = find_index(b, c);
	return (i);
}

int	try_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_spot_a(a, c))
		i = get_stack_size(a) - find_spot_a(a, c);
	if ((i < (get_stack_size(b) - find_index(b, c))) && find_index(b, c))
		i = get_stack_size(b) - find_index(b, c);
	return (i);
}

int	try_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_index(b, c))
		i = get_stack_size(b) - find_index(b, c);
	i = find_spot_a(a, c) + i;
	return (i);
}

int	try_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_spot_a(a, c))
		i = get_stack_size(a) - find_spot_a(a, c);
	i = find_index(b, c) + i;
	return (i);
}
