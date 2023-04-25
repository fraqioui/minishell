/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:26 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/17 10:50:25 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	_and_(t_node *root)
{
	if (executing(root->lchild))
		return (executing(root->rchild));
	//return
}

int	_or_(t_node *root)
{
	if (!executing(root->lchild))
		return (executing(root->rchild));
	//return
}
