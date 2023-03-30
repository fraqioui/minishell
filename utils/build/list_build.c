/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:08:59 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/30 08:28:48 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	list_build(t_node **head, t_node *add)
{
	t_node	*trav;

	if (!head || !add)
		return ;
	if (!*head)
		*head = add;
	else
	{
		trav = *head;
		while (trav->rchild)
			trav = trav->rchild;
		trav->rchild = add;
		add->lchild = trav;
	}
}
