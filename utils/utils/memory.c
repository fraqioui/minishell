/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:09:57 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 00:27:36 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	void	_free_redir(t_redir *trav)
{
	t_redir	*save;

	while (trav)
	{
		free(trav->file);
		save = trav;
		trav = trav->rchild;
		free(save);
	}	
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
		if (root->cmd && root->cmd[0])
			ft_alloc_fail(root->cmd);
		if (root->pre_cmd && root->pre_cmd[0])
			free(root->pre_cmd);
		if (root->redirections)
			_free_redir(root->redirections);
	}
	(free(root), root = NULL);
	return ;
}

void	ret_mem_back(t_node *root)
{
	if (root)
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
		free(env->var);
		free(env->value);
		free(env->env);
		keep = env;
		env = env->next;
		(free(keep), keep = NULL);
	}
	g_gb.env = NULL;
}

void	_free_head(t_node *head)
{
	t_node	*save;

	while (head)
	{
		if (head->pre_cmd)
			free(head->pre_cmd);
		if (head->redirections)
			_free_redir(head->redirections);
		save = head;
		head = head->rchild;
		free(save);
	}
}
