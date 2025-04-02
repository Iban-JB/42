/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:44:29 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/11 16:26:44 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_newline(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_sig = SIGINT;
}

void	sig_quit_action(int signal)
{
	(void)signal;
	g_sig = SIGQUIT;
}

void	sig_int_after_exec(int signal)
{
	(void)signal;
	g_sig = SIGINT;
}

void	sig_here_doc(int signal)
{
	(void) signal;
	printf(" ^C");
	rl_done = 1;
	g_sig = SIGINT;
}

int	rl_hook_function(void)
{
	signal(SIGINT, sig_here_doc);
	return (0);
}
