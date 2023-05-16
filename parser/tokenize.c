/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:08:36 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 16:28:43 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

static	bool	check_left(t_node **head)
{
	if (!head || !*head)
		return (true);
	while (*head && (*head)->rchild)
		*head = (*head)->rchild;
	if ((*head)->tok == NOT)
		return (ft_putstr_fd("bash: syntax error near unexpected token `('\n",
				2), exit_with_status(INCORRECT_USAGE), false);
	return (true);
}

static	bool	which_token_1(t_node **head, char *s, ssize_t *i, ssize_t *par)
{
	t_token	tok;
	t_node	*node;

	tok = check_token(s[*i], s[(*i) + 1]);
	if (!check_true(tok))
	{
		if (!check_tok_syntax(tok, s, i, par))
			return (0);
		node = node_creation_cmd(NULL, NULL, tok, check_pre(tok));
	}
	else
		node = which_token_2(s, tok, i);
	if (!node)
		return (0);
	if (node->tok == LPR)
		if (!check_left(head))
			return (free(node), 0);
	list_build_cmd(head, node);
	return (1);
}

t_node	*tokenize(char *s)
{
	t_node	*head;
	ssize_t	par;
	ssize_t	i;

	par = 0;
	i = 0;
	head = NULL;
	while (s[i])
	{
		if (!which_token_1(&head, s, &i, &par))
			return (_free_head(head), free(s), NULL);
	}
	return (free(s), s = NULL, head);
}
