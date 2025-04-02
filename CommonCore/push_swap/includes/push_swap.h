/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:52:43 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/04/02 19:03:43 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
}	t_stack;

t_stack		*start_parsing(int argc, char **argv);
t_stack		*args_to_stack(char **args, int tp);
t_stack		*get_last_stack(t_stack *lst);
t_stack		*new_stack(int content, t_stack *a, char **args, int tp);
t_stack		*get_last_stack(t_stack *lst);
size_t		size_tab_char_char(char **tab);
void		add_back(t_stack **stack, t_stack *stack_new);
void		error_exit(void);
void		free_stack(t_stack **lst);
void		free_tab_tab_char(char **tab);
void		ra(t_stack **a, int j);
void		rb(t_stack **b, int j);
void		sa(t_stack **a, int j);
void		pa(t_stack **a, t_stack **b, int j);
void		pb(t_stack **stack_a, t_stack **stack_b, int j);
void		rra(t_stack **a, int j);
void		rrb(t_stack **b, int j);
void		ss(t_stack **a, t_stack **b, int j);
void		rr(t_stack **a, t_stack **b, int j);
void		rrr_sub(t_stack **b, int j);
void		rrr(t_stack **a, t_stack **b, int j);
void		sb(t_stack **b, int j);
void		sort(t_stack **stack_a);
void		sort_big(t_stack **stack_a);
void		sort_three(t_stack **stack_a);
void		free_str_stack(char **lst);
void		sort_untill_3(t_stack **stack_a, t_stack **stack_b);
int			check_dups(t_stack *a);
int			get_min(t_stack *a);
int			get_max(t_stack *a);
int			find_index(t_stack *a, int nbr);
int			find_spot_b(t_stack *stack_b, int nbr_push);
int			find_spot_a(t_stack *a, int nbr);
int			is_sorted(t_stack *stack_a);
int			get_stack_size(t_stack *lst);
int			try_rarb_a(t_stack *a, t_stack *b, int c);
int			try_rrarrb_a(t_stack *a, t_stack *b, int c);
int			try_rarrb_a(t_stack *a, t_stack *b, int c);
int			try_rrarb_a(t_stack *a, t_stack *b, int c);
int			try_rarb(t_stack *a, t_stack *b, int c);
int			try_rrarrb(t_stack *a, t_stack *b, int c);
int			try_rrarb(t_stack *a, t_stack *b, int c);
int			try_rarrb(t_stack *a, t_stack *b, int c);
int			best_rotate_a_to_b(t_stack *a, t_stack *b);
int			best_rotate_b_to_a(t_stack *a, t_stack *b);
int			do_rarb(t_stack **a, t_stack **b, int c, char s);
int			do_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			do_rrarb(t_stack **a, t_stack **b, int c, char s);
int			do_rarrb(t_stack **a, t_stack **b, int c, char s);

#endif