/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:49:47 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/30 13:54:14 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

t_node	*parsing(char *input)
{
	char	*s;
	t_node	*head;
	t_token	tok;

	s = ft_strtrim(input, " \t\n\v\r\f");
	if (!s)
		return ;
	tok = check_token(s[0], s[1]);
	if (tok == OR || tok == AND)
	{
		ft_printf("bash: syntax error near unexpected token `%c%c'\n", s[0], s[1]);
		return ;
	}
	else if (tok == PIPE || tok == RPR)
	{
		ft_printf("bash: syntax error near unexpected token `%c'\n", s[0]);
		return ;
	}
	head = tokenize(s);
	if (!head)
		return (NULL);
	head = re_order_command(head);
	head = list_to_tree(head);
	// while (head)
	// {
	// 	if (head->cmd)
	// 	{
	// 		for(int k = 0; head->cmd[k]; k++)
	// 			printf("s:      %s\n", head->cmd[k]);
	// 	}
	// 	printf("tok:      %d\n", head->tok);
	// 	head = head->rchild;
	// }
}

/*
1.  While there are tokens to be read:
2.        Read a token
3.        If it's a number add it to queue
4.        If it's an operator
5.               While there's an operator on the top of the stack with greater precedence:
6.                       Pop operators from the stack onto the output queue
7.               Push the current operator onto the stack
8.        If it's a left bracket push it onto the stack
9.        If it's a right bracket 
10.            While there's not a left bracket at the top of the stack:
11.                     Pop operators from the stack onto the output queue.
12.             Pop the left bracket from the stack and discard it
13. While there are operators on the stack, pop them to the queue
*/