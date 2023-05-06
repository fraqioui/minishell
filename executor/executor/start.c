/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:11:22 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 16:26:12 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	executing(t_node *root)
{
	if (!root)
		return ;
	if (root->tok == AND)
		return (fprintf(stderr, "and\n"), _and_(root));
	if (root->tok == OR)
		return (fprintf(stderr, "or\n"), _or_(root));
	if (root->tok == PIPE)
		return (fprintf(stderr, "pipe\n"), _pipe_(root));
	if (root->tok == NOT)
		return (fprintf(stderr, "not\n"), exec_cmd(root));
}
