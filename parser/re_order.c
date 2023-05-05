/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:07:32 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 08:45:03 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

static	void	_push_(t_node **top, t_node *to_add)
{
	if (!to_add)
		return ;
	else if (!*top)
		*top = to_add;
	else
	{
		(*top)->lchild = to_add;
		to_add->rchild = *top;
		*top = to_add;
	}
}

void	push(t_node **a_head, t_node **b_head, bool flg)
{
	t_node	*sep;

	if (!a_head || !(*a_head))
		return ;
	sep = *a_head;
	*a_head = (*a_head)->rchild;
	sep->rchild = NULL;
	if (*a_head)
		(*a_head)->lchild = NULL;
	if (flg)
		_push_(b_head, sep);
	else
		list_build_cmd(b_head, sep);
}

static	void	pop(t_node **tok_s)
{
	if (!(*tok_s)->rchild)
	{
		free(*tok_s);
		*tok_s = NULL;
	}
	else
	{
		*tok_s = (*tok_s)->rchild;
		free((*tok_s)->lchild);
		(*tok_s)->lchild = NULL;
	}
}

static	void	shunting_yard(t_node **head, t_node **tok_stack,
t_node **new_stack)
{
	while (*head)
	{
		if ((*head)->tok == NOT)
			push(head, new_stack, 0);
		else if ((*head)->tok != LPR && (*head)->tok != RPR)
		{
			while (*tok_stack && (*tok_stack)->precedence
				>= (*head)->precedence)
				push(tok_stack, new_stack, 0);
			push(head, tok_stack, 1);
		}
		else if ((*head)->tok == LPR)
			push(head, tok_stack, 1);
		else if ((*head)->tok == RPR)
		{
			pop(head);
			while ((*tok_stack)->tok != LPR)
				push(tok_stack, new_stack, 0);
			pop(tok_stack);
		}
	}
}

t_node	*re_order_command(t_node **head)
{
	t_node	*tok_stack;
	t_node	*new_stack;

	tok_stack = NULL;
	new_stack = NULL;
	shunting_yard(head, &tok_stack, &new_stack);
	while (tok_stack)
		push(&tok_stack, &new_stack, 0);
	return (new_stack);
}
