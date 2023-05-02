/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:37:39 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 11:21:29 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

t_node	*node_creation_cmd(char *s, t_redir *redir, t_token tok, int precedence)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
	{
		ft_putstr_fd("allocation failed\n", 2);
		return (NULL);
	}
	node->pre_cmd = s;
	node->cmd = NULL;
	node->tok = tok;
	node->precedence = precedence;
	node->redirections = redir;
	node->lchild = NULL;
	node->rchild = NULL;
	return (node);
}

t_redir	*node_creation_redir(char **s, t_token tok)
{
	t_redir	*node;

	if (!s)
		return (NULL);
	node = malloc(sizeof(t_redir));
	if (!node)
	{
		ft_putstr_fd("allocation failed\n", 2);
		return (NULL);
	}
	node->tok = tok;
	node->file = s[0];
	node->flg = 1;
	node->lchild = NULL;
	node->rchild = NULL;
	return (node);
}

t_env	*node_creation_env(char *env, char *var, char *value)
{
	t_env	*node;

	if (!env || !var || !value)
		return (NULL);
	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->env = env;
	node->var = var;
	node->value = value;
	node->next = NULL;
	return (node);
}
