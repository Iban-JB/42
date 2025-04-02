/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:41:46 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/29 17:41:46 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parsing	*init_parsing(t_parsing *parsing, t_gr_coll *gr_coll)
{
	t_parsing	*parsing_info;

	if (!parsing)
	{
		parsing_info = malloc_gr(gr_coll, sizeof(t_parsing), false, false);
		if (!parsing_info)
			return (NULL);
	}
	else
		parsing_info = parsing;
	parsing_info->double_quotes = false;
	parsing_info->simple_quote = false;
	return (parsing_info);
}
