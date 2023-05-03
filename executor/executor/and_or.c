/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:26 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 13:45:36 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	_and_(t_node *root)
{
	executing(root->lchild);
	if (!g_gb.exit_st)
		return (executing(root->rchild));
}

void	_or_(t_node *root)
{
	executing(root->lchild);
	if (g_gb.exit_st)
		return (executing(root->rchild));
}
