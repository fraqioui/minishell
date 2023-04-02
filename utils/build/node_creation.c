/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:37:39 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/30 17:32:02 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

t_node	*node_creation(char **s, t_token tok, int precedence)
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
	node->lchild = NULL;
	node->rchild = NULL;
	return (node);
}
