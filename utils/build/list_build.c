/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:08:59 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/28 16:22:38 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	list_build_cmd(t_node **head, t_node *add)
{
	t_node	*trav;

	if (!head || !add)
		return (0);
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
	return (1);
}

int	list_build_redir(t_redir **head, t_redir *add)
{
	t_redir	*trav;

	if (!head || !add)
		return (0);
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
	return (1);
}
