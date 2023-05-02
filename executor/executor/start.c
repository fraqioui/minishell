/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:11:22 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 11:55:35 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	executing(t_node *root)
{
	if (!root)
		return (-1);
	// if (root->tok == AND)
	// 	return (_and_(root));
	// if (root->tok == OR)
	// 	return (_or_(root));
	if (root->tok == PIPE)
		return (_pipe_(root));
	if (root->tok == NOT)
		return (exec_cmd(root));
	return (-1);
}
