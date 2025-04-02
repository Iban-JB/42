/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:49:01 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/04/02 19:45:08 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(char c, long *res, int sign)
{
	*res = *res * 10 + c - '0';
	if (*res * sign > 2147483647 || *res * sign < -2147483648)
		return (1);
	return (0);
}

int	atoi_parsing(char *str)
{
	int		i;
	int		len;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	len = ft_strlen(str);
	while (str && str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str && str[i] && ft_isdigit(str[i]))
	{
		if (check_overflow(str[i++], &res, sign) == 1)
			return (0);
	}
	if (len == 0 || str[len - 1] == '-' || str[len - 1] == '+')
		return (0);
	return (i == len);
}

int	parse_args(int argc, char **argv, int tp)
{
	int	i;

	i = 0;
	while (i < argc && argv[i])
	{
		if (!atoi_parsing(argv[i]))
		{
			if (tp)
				free_tab_tab_char(argv);
			error_exit();
		}
		i++;
	}
	if (tp == 1)
		free_tab_tab_char(argv);
	if (i == argc - 1)
		return (1);
	return (0);
}

int	parse_args_quoted(char *str)
{
	char	**args;
	int		i;

	args = ft_split(str, ' ');
	i = parse_args(size_tab_char_char(args) + 1, args, 1);
	return (i);
}

t_stack	*start_parsing(int argc, char **argv)
{
	t_stack	*a;
	char	**tp;

	a = NULL;
	if (argc < 2)
		exit(0);
	else if (argc == 2 && argv[1][0] && parse_args_quoted(argv[1]))
	{
		tp = ft_split(argv[1], ' ');
		if (!tp)
			error_exit();
		a = args_to_stack(tp, 1);
	}
	else if (argc >= 3)
	{
		parse_args(argc, argv + 1, 0);
		a = args_to_stack(argv + 1, 0);
	}
	return (a);
}
