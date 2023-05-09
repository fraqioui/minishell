/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_hlp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:15:27 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/08 09:12:29 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

static	void	handler(int sig)
{
	(void)sig;
	if (!g_gb.under_exec)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_gb.exit_st = 1;
	}
}

void	_signal_start(void)
{
	rl_catch_signals = 0;
	if (signal(SIGINT, handler) == SIG_ERR
		|| signal(SIGQUIT, SIG_IGN) == SIG_ERR
		|| signal(SIGTSTP, SIG_IGN) == SIG_ERR)
		return (print_error(2, "signal", strerror(errno)), exit_with_status(1));
}

void	_signal_middle_exec(void)
{
	if (signal(SIGINT, SIG_DFL) == SIG_ERR
		|| signal(SIGQUIT, SIG_DFL) == SIG_ERR
		|| signal(SIGTSTP, SIG_DFL) == SIG_ERR)
		return (print_error(2, "signal", strerror(errno)), exit_with_status(1));
}

void	free_space(void)
{
	rl_clear_history();
	free_env();
}
