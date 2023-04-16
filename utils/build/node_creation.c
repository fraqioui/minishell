/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:37:39 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/16 11:36:51 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

t_node	*node_creation_cmd(char **s, t_redir *redir, t_token tok, int precedence)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
	{
		ft_putstr_fd("allocation failed\n", 2);
		return (NULL);
	}
	node->tok = tok;
	node->cmd = s;
	node->precedence = precedence;
	node->redirections = redir;
	node->lchild = NULL;
	node->rchild = NULL;
	return (node);
}

t_redir	*node_creation_redir(char *s, t_token tok)
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
	node->file = s;
	node->lchild = NULL;
	node->rchild = NULL;
	return (node);
}
