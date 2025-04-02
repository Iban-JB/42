/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:05:20 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/11 14:25:33 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	create_new_error(char *msg_error, char *msg, int *start_end)
{
	char	c;

	if (start_end)
	{
		c = msg[start_end[1]];
		msg[start_end[1]] = '\0';
		ft_dprintf(STDERR_FILENO, "%s%s `%s'\n", \
		MINISHELL, msg_error, msg + start_end[0]);
		msg[start_end[1]] = c;
	}
	else
		ft_dprintf(STDERR_FILENO, "%s%s %s\n", MINISHELL, msg_error, msg);
	return (true);
}
