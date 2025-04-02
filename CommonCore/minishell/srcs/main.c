/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:40:52 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/11 16:04:16 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	call_readline(char **env, t_gr_coll *gr_coll);

static void	init_minishell_info(t_minishell_info **minishell_info, \
t_gr_coll *gr_coll, char **envp);

int	g_sig = 0;

int	main(int argc, char **argv, char **envp)
{
	t_gr_coll	gr_coll;
	char		**new_env;

	g_sig = 0;
	errno = 0;
	gr_coll = (t_gr_coll){0};
	(void)argc;
	(void)argv;
	new_env = cp_envp(envp, &gr_coll);
	call_readline(new_env, &gr_coll);
	return (0);
}

static int	call_readline(char **env, t_gr_coll *gr_coll)
{
	t_minishell_info	*minishell_info;
	struct sigaction	act;

	act = (struct sigaction){0};
	act.sa_handler = SIG_IGN;
	init_minishell_info(&minishell_info, gr_coll, env);
	while (1)
	{
		minishell_info->type_data = NULL;
		sigaction(SIGQUIT, &act, NULL);
		signal(SIGINT, sig_newline);
		minishell_info->parsing_info->line = readline("$minishell ");
		g_sig = 0;
		minishell_info->gr_coll->line = minishell_info->parsing_info->line;
		add_node(minishell_info->parsing_info->line, gr_coll);
		if (g_sig == SIGINT)
			minishell_info->exit_value = 130;
		if (!minishell_info->parsing_info->line)
			ft_exit(minishell_info, false, -1, NULL);
		if (g_sig != SIGINT)
			parse_line(minishell_info);
		free_node(gr_coll, minishell_info->parsing_info->line, false);
		init_parsing(minishell_info->parsing_info, NULL);
	}
}

static void	init_minishell_info(t_minishell_info **minishell_info, \
t_gr_coll *gr_coll, char **envp)
{
	*minishell_info = malloc_gr(gr_coll, sizeof(t_minishell_info), \
	false, false);
	(*minishell_info)->env = envp;
	(*minishell_info)->parsing_info = init_parsing(NULL, gr_coll);
	(*minishell_info)->exit_value = 0;
	(*minishell_info)->gr_coll = gr_coll;
}
