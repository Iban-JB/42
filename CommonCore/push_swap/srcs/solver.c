/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:06:13 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/25 18:06:29 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (get_min(*stack_a) == (*stack_a)->nbr)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (get_max(*stack_a) == (*stack_a)->nbr)
	{
		ra(stack_a, 0);
		if (!is_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (find_index(*stack_a, get_max(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}

void	sort_untill_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (get_stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = best_rotate_a_to_b(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == try_rarb(*stack_a, *stack_b, tmp->nbr))
				i = do_rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == try_rrarrb(*stack_a, *stack_b, tmp->nbr))
				i = do_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == try_rarrb(*stack_a, *stack_b, tmp->nbr))
				i = do_rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == try_rrarb(*stack_a, *stack_b, tmp->nbr))
				i = do_rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (get_stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (get_stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (get_stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		sort_untill_3(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = best_rotate_b_to_a(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == try_rarb_a(*stack_a, *stack_b, tmp->nbr))
				i = do_rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == try_rarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = do_rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == try_rrarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = do_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == try_rrarb_a(*stack_a, *stack_b, tmp->nbr))
				i = do_rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (get_stack_size(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		i = find_index(*stack_a, get_min(*stack_a));
		if (i < get_stack_size(*stack_a) - i)
			while ((*stack_a)->nbr != get_min(*stack_a))
				ra(stack_a, 0);
		else
			while ((*stack_a)->nbr != get_min(*stack_a))
				rra(stack_a, 0);
	}
}
