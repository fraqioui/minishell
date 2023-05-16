/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:49:47 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 16:27:54 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

t_node	*parsing(char *input)
{
	char	*s;
	t_node	*head;

	s = ft_strtrim(input, " \t\n\v\r\f");
	free(input);
	if (!s || !check_tok(s))
		return (free(s), NULL);
	head = tokenize(s);
	if (!head)
		return (NULL);
	head = re_order_command(&head);
	while (head->rchild)
		head = head->rchild;
	head = list_to_tree(head);
	return (head);
}
