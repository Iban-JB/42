/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 09:49:38 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/27 18:09:23 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = start_parsing(argc, argv);
	if (!a || check_dups(a))
		error_exit();
	if (!is_sorted(a))
		sort(&a);
	free_stack(&a);
	return (0);
}
