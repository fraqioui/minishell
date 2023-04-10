/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:07:32 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/31 21:47:27 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

int	check_spaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

char	**fill_cmd(char *s, int l, int *k)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(sizeof(char) * (l + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < l)
	{
		if (s[*k] == 34 || s[*k] == 39)
		{
			j = check_next_quote(&s[(*k) + 1]) + i + 1;
			while (i < j)
				ret[i++] = s[(*k)++];
		}
		if (s[*k] == 32)
			s[*k] = 127;
		ret[i++] = s[(*k)++];
	}
	ret[i] = 0;
	return (ft_split(ret, 127));
}

static	void	_push_(t_node **top, t_node *to_add)
{
	if (!to_add)
		return ;
	else if (!*top)
	{
		to_add->rchild = NULL;
		*top = to_add;
	}
	else
	{
		(*top)->lchild = to_add;
		to_add->rchild = *top;
		*top = to_add;
	}
}

static	void	push(t_node **a_head, t_node **b_head)
{
	t_node	*sep;

	if (!a_head || !(*a_head))
		return ;
	sep = *a_head;
	*a_head = (*a_head)->rchild;
	if (*a_head)
		(*a_head)->lchild = NULL;
	_push_(b_head, sep);
}

static	void	pop(t_node **tok_s)
{
	*tok_s = (*tok_s)->rchild;
	free((*tok_s)->lchild);
	(*tok_s)->lchild = NULL;
}

t_node	*re_order_command(t_node **head)
{
	t_node	*tok_stack;
	t_node	*new_stack;

	tok_stack = NULL;
	new_stack = NULL;
	while (*head)
	{
		if ((*head)->tok == NOT)
			push(head, &new_stack);
		else if ((*head)->tok != LPR && (*head)->tok != RPR)
		{
			while (tok_stack && tok_stack->precedence >= (*head)->precedence)
				push(&tok_stack, &new_stack);
			push(head, &tok_stack);
		}
		else if ((*head)->tok == LPR)
			push(head, &tok_stack);
		else if ((*head)->tok == RPR)
		{
			pop(head);
			while (tok_stack->tok != LPR)
				push(&tok_stack, &new_stack);
			pop(&tok_stack);
		}
	}
	while (tok_stack)
		push(&tok_stack, &new_stack);
	return (new_stack);
}

/*check syntax error:

&& || | :
	left: [WSPACE] (STRING | LPR)
	right: [WSPACE] (STRING | REDIRECT | RPR)

(:
	 left: [WSPACE] (AND | OR | PIPE | LPR)
	 right: [WSPACE] (STRING | REDIRECT | LPR)

):
	 left: [WSPACE] (STRING | RPR)
	 right: [WSPACE] (AND | OR | PIPE | RPR)

REDIRECT:
	 right: [WSPACE] STRING
# () empty parentheses
*/
