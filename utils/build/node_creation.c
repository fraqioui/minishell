/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:37:39 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 13:21:10 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

t_node	*node_creation_cmd(char *s, t_redir *redir, t_token tok, int precedence)
{
	t_node	*node;

	node = _malloc_(sizeof(t_node));
	if (!node)
		return (NULL);
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
	node = _malloc_(sizeof(t_redir));
	if (!node)
		return (NULL);
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

	node = _malloc_(sizeof(t_env));
	if (!node)
		return (NULL);
	node->env = env;
	node->var = var;
	node->value = value;
	node->next = NULL;
	return (node);
}

static	void	*_malloc_mem(size_t size)
{
	void	*ptr;

	ptr = _malloc_(size);
	if (!ptr)
		return (print_error("_malloc_", strerror(errno)),
			exit_with_status(1), NULL);
	return (ptr);
}

t_mem	*node_creation_mem(void	*ptr)
{
	t_mem	*node;

	node = _malloc_mem(sizeof(t_mem));
	if (!node)
		return (NULL);
	node->ptr = ptr;
	node->next = NULL;
	return (node);
}
