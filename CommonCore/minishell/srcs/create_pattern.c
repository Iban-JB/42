/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:18:16 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 17:51:31 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_pattern(char *line, int *start_end, t_info_crt_cmd \
*info_crt_cmd, char *pattern);

char	**create_pattern(t_info_crt_cmd *info_crt_cmd)
{
	int		len_pattern;
	char	*line;
	char	*pattern;
	char	**tab_pattern;

	line = info_crt_cmd->line;
	len_pattern = find_len_pattern(line, info_crt_cmd->start_end, info_crt_cmd);
	if (!len_pattern)
		return (NULL);
	pattern = malloc_gr(info_crt_cmd->gr_coll, \
	sizeof(char) * (len_pattern + 1), false, false);
	fill_pattern(line, info_crt_cmd->start_end, info_crt_cmd, pattern);
	tab_pattern = ft_split_pattern(info_crt_cmd->gr_coll, pattern);
	free_node(info_crt_cmd->gr_coll, pattern, false);
	return (tab_pattern);
}

static void	fill_pattern(char *line, int *start_end, \
t_info_crt_cmd *info_crt_cmd, char *pattern)
{
	int	i;
	int	len;

	len = 0;
	i = start_end[0] - 1;
	while (++i < start_end[1])
	{
		if (line[i] == -2)
		{
			pattern[len++] = line[i];
			while (line[++i] != -2)
				pattern[len++] = line[i];
			pattern[len++] = line[i];
		}
		else if (line[i] == '$' && (ft_isalnum(line[i + 1]) || \
		line[i + 1] == '_' || line[i + 1] == '?'))
		{
			len += fill_pattern_var(&i, line, info_crt_cmd, pattern + len);
			i--;
		}
		else
			pattern[len++] = line[i];
	}
	pattern[len] = 0;
}

int	fill_pattern_var(int *i, char *line, \
t_info_crt_cmd *info_crt_cmd, char *pattern)
{
	int		len_name_var;
	int		i_start;
	char	*var;

	i_start = *i;
	if (line[*i + 1] == '?')
	{
		*i = *i + 2;
		return (fill_itoa(info_crt_cmd->exit_value, pattern));
	}
	else if (ft_isdigit(line[*i + 1]))
	{
		*i = *i + 2;
		return (0);
	}
	else
	{
		len_name_var = find_len_name_var(line, i);
		var = find_var_env(info_crt_cmd->envp, \
		line + i_start + 1, len_name_var);
		if (!var)
			return (0);
		ft_strcpy(pattern, var + len_name_var + 1);
	}
	return ((int)(ft_strlen(var) - len_name_var - 1));
}

int	fill_itoa(int n, char *s)
{
	long int	long_n;
	int			i;
	int			nb_char;

	long_n = (long int)n;
	if (long_n < 0)
	{
		long_n *= -1;
		s[0] = '-';
	}
	i = ft_len_number(n);
	nb_char = i;
	s[i] = 0;
	if (long_n == 0)
		s[i - 1] = '0';
	while (long_n != 0)
	{
		i--;
		s[i] = long_n % 10 + '0';
		long_n /= 10;
	}
	return (nb_char);
}
