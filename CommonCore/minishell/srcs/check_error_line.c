/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:11:46 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/11 14:28:46 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	check_error_first_arg(t_minishell_info *minishell_info)
{
	char	*line;
	int		i;

	i = 0;
	line = minishell_info->parsing_info->line;
	while (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')
		i++;
	if (line[i] == '|')
	{
		minishell_info->exit_value = EXIT_PARSING;
		return (create_new_error(ERROR_UNEXPECTED_TOKEN, "`|'", NULL));
	}
	return (false);
}
