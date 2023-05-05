/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:11:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 08:47:10 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

bool	_expanding_(t_node *node)
{
	bool	flg;

	node->cmd = parse_cmd(node->pre_cmd);
	if (!node->cmd)
		return (0);
	if (node->redirections)
	{
		while (node->redirections)
		{
			node->redirections->file
				= parse_redir(node->redirections->file, &flg);
			if (!node->redirections->file)
				return (0);
			node->redirections->flg = flg;
			node->redirections = node->redirections->rchild;
		}
	}
	return (1);
}
