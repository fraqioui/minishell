/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:37:04 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 22:29:42 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

ssize_t	find_c(char *s)
{
	ssize_t	i;

	i = 0;
	while (*s)
	{
		if (*s == '=')
			return (i);
		s++;
		i++;
	}
	return (-1);
}

static	void	initialize_env(char **env)
{
	ssize_t	index;

	if (!env || !env[0])
		return ;
	g_gb.env = NULL;
	while (*env)
	{
		index = find_c(*env);
		lstadd_back_env(&g_gb.env, node_creation_env(ft_strdup(*env),
				ft_substr(*env, 0, index), ft_substr(*env, index + 1,
					ft_strlen(*env) - index)));
		env++;
	}
}

static	void	keep_in_out(int *fd_in, int *fd_out)
{
	*fd_in = dup(STDIN_FILENO);
	*fd_out = dup(STDOUT_FILENO);
	if (*fd_in < 0 || *fd_out < 0)
		print_error("dup", strerror(errno), 1, 0);
}

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
	if (signal(SIGINT, handler) == SIG_ERR
		|| signal(SIGQUIT, SIG_IGN) == SIG_ERR
		|| signal(SIGTSTP, SIG_IGN) == SIG_ERR)
		print_error("signal", strerror(errno), 1, 1);
}

void	initialize(char **env, int *fd_in, int *fd_out)
{
	g_gb.under_exec = 0;
	initialize_env(env);
	keep_in_out(fd_in, fd_out);
}

void	_signal_middle_exec(void)
{
	if (signal(SIGINT, SIG_DFL) == SIG_ERR
		|| signal(SIGQUIT, SIG_DFL) == SIG_ERR
		|| signal(SIGTSTP, SIG_DFL) == SIG_ERR)
		print_error("signal", strerror(errno), 1, 1);
}
