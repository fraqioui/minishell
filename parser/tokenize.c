/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:08:36 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/28 16:10:32 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

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
			return (NULL);
	}
	// t_node *trav = head;
	// while (trav)
	// {
	// 	printf("tok: %d\t", trav->tok);
	// 	if (trav->pre_cmd)
	// 		printf("s: %s\n", trav->pre_cmd);
	// 	if (trav->redirections)
	// 	{
	// 		printf("redirections: ");
	// 		while (trav->redirections)
	// 		{
	// 			printf("%d\t-%s-\t", trav->redirections->tok, trav->redirections->file);
	// 			trav->redirections = trav->redirections->rchild;
	// 		}
	// 	}
	// 	puts("\n");
	// 	trav = trav->rchild;
	// }
	return (head);
}
