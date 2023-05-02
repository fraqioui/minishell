/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:01:45 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 08:31:43 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

t_gb	g_gb;

int	main(int ac, char **av, char **env)
{
	char	*input;
	int		fd_in;
	int		fd_out;

	(void)ac;
	(void)av;
	initialize(env, &fd_in, &fd_out);
	while (1)
	{
		_signal_start();
		input = readline("minibash$ ");
		if (!input)
			break ;
		g_gb.under_exec = 1;
		add_history(input);
		executing(parsing(input));
		g_gb.under_exec = 0;
		free(input);
	}
	//free under exec
}

	// struct sigaction	s;
	// s.sa_handler = sigint_handler;
	// sigemptyset(&s.sa_mask);
	// s.sa_flags = SA_RESTART;
	// sigaction(SIGINT, &s, NULL);