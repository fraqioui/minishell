/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:45:59 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/18 10:35:22 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

static	int	check_syntax_help(t_token tok, t_token next)
{
	if (tok == OR || tok == AND || tok == PIPE)
	{
		if (next == NOT || next == IN || next == OUT
			|| next == APPEND || next == LPR)
			return (1);
	}
	if (tok == LPR)
	{
		if (next == NOT || next == IN || next == OUT
			|| next == APPEND || next == LPR)
			return (1);
	}
	if (tok == RPR)
	{
		if (next == AND || next == OR || next == PIPE
			|| next == RPR || next == END)
			return (1);
	}
	if (tok == IN || tok == OUT || tok == APPEND || tok == HEREDOC)
	{
		if (next == NOT)
			return (1);
	}
	return (0);
}

int	check_syntax(t_token tok, char *s)
{
	t_token	next;

	next = check_token(*s, *(s + 1));
	if (check_syntax_help(tok, next))
		return (1);
	if (next == END)
		ft_printf("bash: syntax error near unexpected token `newline'\n");
	else if (next == AND || next == OR || next == APPEND || next == HEREDOC)
		ft_printf("bash: syntax error near unexpected token `%c%c'\n",
			*s, *(s + 1));
	else
		ft_printf("bash: syntax error near unexpected token `%c'\n", *s);
	return (0);
}

int	check_next_quote(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
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

int	check_pre(t_token tok)
{
	if (tok == IN || tok == OUT || tok == APPEND || tok == HEREDOC)
		return (4);
	if (tok == PIPE)
		return (3);
	if (tok == OR || tok == AND)
		return (2);
	return (1);
}
