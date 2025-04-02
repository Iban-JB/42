/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:50:34 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/04/02 19:04:18 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*args_to_stack(char **args, int tp)
{
	size_t	i;
	size_t	len;
	t_stack	*a;
	t_stack	*first;

	i = 1;
	first = new_stack(ft_atoi(args[0]), 0, args, tp);
	a = first;
	len = size_tab_char_char(args);
	while (i < len)
	{
		a->next = new_stack(ft_atoi(args[i]), first, args, tp);
		a->index = i;
		a = a->next;
		i++;
	}
	if (tp)
		free_tab_tab_char(args);
	return (first);
}

size_t	size_tab_char_char(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

t_stack	*new_stack(int content, t_stack *a, char **args, int tp)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
	{
		if (tp)
			free_tab_tab_char(args);
		free_stack(&a);
		error_exit();
	}
	new->nbr = content;
	new->next = NULL;
	return (new);
}

void	add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(get_last_stack(*stack))->next = stack_new;
}
