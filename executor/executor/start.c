/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:11:22 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/03 14:13:47 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	executing(t_node *root)
{
	if (!root)
		return ;
	if (root->tok == AND)
		return (puts("and"), _and_(root));
	if (root->tok == OR)
		return (puts("or"), _or_(root));
	if (root->tok == PIPE)
		return (puts("pipe"), _pipe_(root));
	if (root->tok == NOT)
		return (puts("not"), exec_cmd(root));
}
