/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:11:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 16:08:45 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

bool	_expanding_(t_node *node)
{
	bool	flg;
	t_redir	*redir;

	flg = 1;
	node->cmd = parse_cmd(node->pre_cmd);
	if (!node->cmd)
		return (0);
	node->pre_cmd = NULL;
	redir = node->redirections;
	if (redir)
	{
		while (redir)
		{
			redir->file
				= parse_redir(redir, redir->file, &flg);
			if (!redir->file[0])
				return (ft_putstr_fd("bash: ambiguous redirect\n", 2),
					exit_with_status(1), 0);
			if (!redir->file)
				return (0);
			redir->flg = flg;
			redir = redir->rchild;
		}
	}
	return (1);
}
