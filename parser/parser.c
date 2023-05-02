/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:49:47 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/28 15:13:43 by fraqioui         ###   ########.fr       */
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
		printf("%d\t%s\n", root->tok, root->pre_cmd);
	else
		printf("%d\n", root->tok);
	return ;
}

t_node	*parsing(char *input)
{
	char	*s;
	t_node	*head;

	s = ft_strtrim(input, " \t\n\v\r\f");
	if (!s || !check_tok(s))
		return (NULL);
	head = tokenize(s);
	if (!head)
		return (NULL);
	head = re_order_command(&head);
	while (head->rchild)
		head = head->rchild;
	head = list_to_tree(head);
	print(head);
	return (head);
}
