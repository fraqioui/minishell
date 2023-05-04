/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:37:04 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 11:56:33 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

ssize_t	find_c(char *s, char c)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
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
		index = find_c(*env, '=');
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
		return (print_error("dup", strerror(errno)), exit_with_status(1));
}

void	initialize(char **env, int *fd_in, int *fd_out)
{
	g_gb.under_exec = 0;
	g_gb.mem = NULL;
	initialize_env(env);
	keep_in_out(fd_in, fd_out);
}
