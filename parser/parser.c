/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:49:47 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/31 08:46:05 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

static void	print(t_node *root)
{
	if (root->tok != NOT)
	{
		print(root->lchild);
		print(root->rchild);
	}
	if (root->tok == NOT)
		printf("%d\t%s\n", root->tok, root->cmd[0]);
	else
		printf("%d\n", root->tok);
	return ;
}

t_node	*parsing(char *input)
{
	char	*s;
	t_node	*head;
	t_token	tok;

	s = ft_strtrim(input, " \t\n\v\r\f");
	if (!s)
		return (NULL);
	tok = check_token(s[0], s[1]);
	if (tok == OR || tok == AND)
	{
		ft_printf("bash: syntax error near unexpected token `%c%c'\n", s[0], s[1]);
		return (NULL);
	}
	else if (tok == PIPE || tok == RPR)
	{
		ft_printf("bash: syntax error near unexpected token `%c'\n", s[0]);
		return (NULL);
	}
	head = tokenize(s);
	if (!head)
		return (NULL);
	head = re_order_command(&head);
	t_node *trav;
	trav = head;
	puts("list:  ");
	while (trav)
	{
		printf("%d ", trav->tok);
		trav = trav->rchild;
	}
	puts("\n");
	head = list_to_tree(head);
	puts("here\n");
	exit(0);
	print(head);
	return (head);
}
