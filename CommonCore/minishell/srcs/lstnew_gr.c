/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_gr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:58:34 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 14:23:10 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*lstnew_gr(void *content, t_gr_coll *gr_coll)
{
	t_list	*new_list;

	new_list = malloc_gr(gr_coll, sizeof(t_list), false, false);
	if (new_list == NULL)
		return (NULL);
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}
