/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:01:45 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/12 13:07:38 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

void	sigint_handler(int signo)
{
	(void)signo;
}

int	main(int ac, char **av, char **env)
{
	struct sigaction	s;
	char				*input;

	s.sa_handler = sigint_handler;
	sigemptyset(&s.sa_mask);
	s.sa_flags = SA_RESTART;
	sigaction(SIGINT, &s, NULL);
	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		input = readline("minibash$ ");
		if (!input)
			break ;
		printf("--%s--\n", input);
		executing(parsing(input));
		free(input);
	}
}
