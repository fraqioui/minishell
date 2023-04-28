/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:49:47 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/28 13:05:27 by fraqioui         ###   ########.fr       */
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

static	int	check_tok(char *s)
{
	t_token	tok;

	tok = check_token(s[0], s[1]);
	if (tok == OR || tok == AND)
	{
		ft_printf("bash: syntax error near unexpected token `%c%c'\n",
			s[0], s[1]);
		return (0);
	}
	else if (tok == PIPE || tok == RPR)
	{
		ft_printf("bash: syntax error near unexpected token `%c'\n", s[0]);
		return (0);
	}
	return (1);
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
