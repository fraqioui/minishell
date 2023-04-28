/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:11:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/28 12:25:17 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	_expanding_(t_node *node)
{
	node->cmd = eliminate_quotes(node->pre_cmd); //should free
	if (!node->cmd)
		return (-1);
	// if (node->redirections)
	// {
	// 	while (node->redirections)
	// 	{
	// 		node->redirections->file = eliminate_quotes(node->redirections->file);
	// 		if (!node->redirections->file)
	// 			return (-1);
	// 		node->redirections = node->redirections->rchild;
	// 	}
	// }
	return (0);
}
