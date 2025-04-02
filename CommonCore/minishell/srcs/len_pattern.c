/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_pattern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:20:31 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/06 17:51:31 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_end_var(char c);

int				nb_space_name(char *value_env);

int	find_len_pattern(char *line, int *start_end, t_info_crt_cmd *info_crt_cmd)
{
	int		len;
	int		i;

	len = 0;
	i = start_end[0] - 1;
	while (++i < start_end[1])
	{
		if (line[i] == -2)
		{
			len += 2;
			while (line[++i] != -2)
				len++;
		}
		else if (line[i] == '$' && (ft_isalnum(line[i + 1]) || \
		line[i + 1] == '_' || line[i + 1] == '?'))
		{
			len += len_var(&i, line, info_crt_cmd->envp, \
			info_crt_cmd->exit_value);
			i--;
		}
		else
			len++;
	}
	return (len);
}

int	len_var(int *i, char *line, char **envp, int exit_value)
{
	int		len_name_var;
	int		i_start;
	char	*var;

	i_start = *i;
	if (line[*i + 1] == '?')
	{
		*i = *i + 2;
		return (ft_len_number(exit_value));
	}
	else if (ft_isdigit(line[*i + 1]))
	{
		*i = *i + 2;
		return (0);
	}
	else
	{
		len_name_var = find_len_name_var(line, i);
		var = find_var_env(envp, line + i_start + 1, len_name_var);
		if (!var)
			return (0);
	}
	return ((int)(ft_strlen(var) - len_name_var - 1));
}

char	*find_var_env(char **env, char *name_var, int len_name_var)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], name_var, len_name_var) && \
		(int)ft_strlen(env[i]) > len_name_var && env[i][len_name_var] == '=')
			return (env[i]);
	}
	return (NULL);
}

int	find_len_name_var(char *name, int *i)
{
	int	len;

	len = 0;
	*i = *i + 1;
	while (name[*i])
	{
		if (is_end_var(name[*i]))
			return (len);
		len++;
		*i = *i + 1;
	}
	return (len);
}

static t_bool	is_end_var(char c)
{
	if (ft_isalnum((int)c) || c == '_')
		return (false);
	return (true);
}
