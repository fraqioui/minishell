/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:41:35 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/30 15:29:12 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

t_node	*list_to_tree(t_node *head)
{
	if (head->tok != NOT)
	{
		head->rchild = list_to_tree(head->lchild);
		head->lchild = list_to_tree(head->lchild);
	}
	return (head);
}
