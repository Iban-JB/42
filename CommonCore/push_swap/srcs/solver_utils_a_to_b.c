/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:44:26 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/25 15:36:43 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	try_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_spot_b(b, c);
	if (i < find_index(a, c))
		i = find_index(a, c);
	return (i);
}

int	try_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_spot_b(b, c))
		i = get_stack_size(b) - find_spot_b(b, c);
	if ((i < (get_stack_size(a) - find_index(a, c))) && find_index(a, c))
		i = get_stack_size(a) - find_index(a, c);
	return (i);
}

int	try_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_index(a, c))
		i = get_stack_size(a) - find_index(a, c);
	i = find_spot_b(b, c) + i;
	return (i);
}

int	try_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_spot_b(b, c))
		i = get_stack_size(b) - find_spot_b(b, c);
	i = find_index(a, c) + i;
	return (i);
}
