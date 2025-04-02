/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:19:48 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/07 17:03:25 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	double_quote(char *c, t_parsing *parsing);

void	remove_quotes(t_parsing *parsing_info)
{
	int		i;
	char	*line;

	i = -1;
	line = parsing_info->line;
	while (line[++i])
	{
		if (line[i] == '\"')
		{
			if (parsing_info->simple_quote == false && \
			parsing_info->double_quotes == false)
			{
				parsing_info->double_quotes = true;
				line[i] = -1;
			}
			else if (parsing_info->double_quotes == true)
			{
				parsing_info->double_quotes = false;
				line[i] = -1;
			}
		}
		else if (line[i] == '\'')
			double_quote(line + i, parsing_info);
	}
}

static void	double_quote(char *c, t_parsing *parsing)
{
	if (parsing->simple_quote == false && \
			parsing->double_quotes == false)
	{
		*c = -2;
		parsing->simple_quote = true;
	}
	else if (parsing->simple_quote == true)
	{
		*c = -2;
		parsing->simple_quote = false;
	}
}
