/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:21:07 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 14:11:10 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	check_char_next_arg(char *line, int *i, int *start_end);

int	*find_next_arg(char *line, int i, t_gr_coll *gr_coll)
{
	int	*start_end;

	start_end = malloc_gr(gr_coll, sizeof(int) * 2, false, false);
	if (!start_end)
		return (NULL);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	start_end[0] = i;
	if (is_special_char(line + i))
	{
		start_end[1] = i + is_special_char(line + i);
		return (start_end);
	}
	while (line[i])
	{
		if (check_char_next_arg(line, &i, start_end) == false)
			return (start_end);
	}
	start_end[1] = i;
	return (start_end);
}

int	find_end_quotes(char *line, int i)
{
	char	c;

	c = line[i];
	if (c == -1 || c == -2)
	{
		while (line[++i] != c && line[i])
			;
		if (!line[i])
			return (-1);
		return (++i);
	}
	return (i);
}

int	is_special_char(char *c)
{
	if ((*c == '>' && *(c + 1) == '>') || \
	(*c == '<' && *(c + 1) == '<'))
		return (2);
	if (*c == ' ' || *c == '\t' || *c == '\n' || *c == '<' || \
	*c == '>' || *c == '|')
		return (1);
	return (0);
}

static t_bool	check_char_next_arg(char *line, int *i, int *start_end)
{
	if (line[*i] == -1 || line[*i] == -2)
	{
		*i = find_end_quotes(line, *i);
		if (*i == -1)
		{
			start_end[1] = *i;
			return (false);
		}
	}
	else if (line[*i])
	{
		if (is_special_char(line + *i))
		{
			start_end[1] = *i;
			return (false);
		}
		*i = *i + 1;
	}
	return (true);
}
