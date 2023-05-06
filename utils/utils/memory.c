/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:09:57 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 21:55:20 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	*malloc_error(int errnum)
{
	print_error(2, "malloc", strerror(errnum));
	exit_with_status(1);
	return (NULL);
}

static	void	free_tree(t_node *root)
{
	if (root->tok != NOT)
	{
		free_tree(root->lchild);
		free_tree(root->rchild);
	}
	if (root->tok == NOT)
	{
		if (root->cmd)
			ft_alloc_fail(root->cmd);
		if (root->pre_cmd)
			free(root->pre_cmd);
		if (root->redirections)
		{
			while (root->redirections)
			{
				free(root->redirections->file);
				root->redirections = root->redirections->rchild;
				if (root->redirections)
					free(root->redirections->lchild);
			}
		}
	}
	(free(root), root = NULL);
	return ;
}

void	ret_mem_back(t_node *root)
{
	free_tree(root);
	root = NULL;
}

void	free_env(void)
{
	t_env	*env;
	t_env	*keep;

	env = g_gb.env;
	keep = env;
	while (env)
	{
		keep = env;
		env = env->next;
		(free(keep), keep = NULL);
	}
	g_gb.env = NULL;
}
