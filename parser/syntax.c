/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:45:59 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/30 13:27:25 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

int	check_syntax(t_token tok, char *s)
{
	t_token	next;

	next = check_token(*s, *(s + 1));
	if (tok == OR || tok == AND || tok == PIPE)
	{
		if (next == NOT || next == IN || next == OUT || next == APPEND || next == LPR)
			return (1);
	}
	if (tok == LPR)
	{
		if (next == NOT || next == IN || next == OUT || next == APPEND || next == LPR)
			return (1);
	}
	if (tok == RPR)
	{
		if (next == AND || next == OR || next == PIPE || next == RPR || next == END)
			return (1);
	}
	if (tok == IN || tok == OUT || tok == APPEND || tok == HEREDOC)
	{
		if (next == NOT)
			return (1);
	}
	if (next == END)
		ft_printf("syntax error: incomplete command\n");
	else if (next == AND || next == OR || next == APPEND || next == HEREDOC)
		ft_printf("bash: syntax error near unexpected token `%c%c'\n", *s, *(s + 1));
	else
		ft_printf("bash: syntax error near unexpected token `%c'\n", *s);
	return (0);
}

int	check_next_quote(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
			return (i);
		i++;
		s++;
	}
	ft_putstr_fd("syntax error: unclosed quotes\n", 2);
	return (-1);
}

int	check_rpr(char *s, int i)
{
	while (*s)
	{
		if (*s == ')')
			return (i);
		i++;
		s++;
	}
	ft_putstr_fd("syntax error: unclosed parentheses\n", 2);
	return (-1);
}
