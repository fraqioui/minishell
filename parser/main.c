/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:01:45 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 18:20:35 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

t_gb	g_gb;

// static void	print(t_node *root)
// {
// 	if (root->tok != NOT)
// 	{
// 		print(root->lchild);
// 		print(root->rchild);
// 	}
// 	if (root->tok == NOT)
// 		printf("%d\t%s\t%s\n", root->tok, root->cmd[0], root->cmd[1]);
// 	else
// 		printf("%d\n", root->tok);
// 	return ;
// }

int	main(int ac, char **av, char **env)
{
	char	*input;
	int		fd_in;
	int		fd_out;
	t_node	*root;

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
		root = parsing(input);
		executing(root);
		g_gb.under_exec = 0;
		// print(root);
		ret_mem_back(root);
		set_in_out(fd_in, fd_out);
	}
	free_env();
	//free under exec
}
