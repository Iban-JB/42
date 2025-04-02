/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:14:23 by rperrot           #+#    #+#             */
/*   Updated: 2024/05/26 22:14:23 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	line_is_empty(char *line)
{
	int	i;

	i = -1;
	while (line[++i] == ' ' || line[i] == '\n' || line[i] == '\t')
		;
	if (!line[i])
		return (true);
	return (false);
}
