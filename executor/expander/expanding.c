/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:11:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/25 10:41:16 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	_expanding_(t_node *node)
{
	int	i;

	i = -1;
	if (!eliminate_quotes(node->cmd))
		return (-1);
	if (node->redirections)
	{
		while (node->redirections)
		{
			node->redirections->file = eliminate_quotes(node->redirections->file);
			if (!node->redirections->file)
				return (-1);
			node->redirections = node->redirections->rchild;
		}
	}
	return (0);
}
