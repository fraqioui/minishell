/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:45:59 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/28 16:17:36 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

static	bool	check_syntax_help(t_token tok, t_token next)
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

bool	check_syntax(t_token tok, char *s)
{
	t_token	next;

	next = check_token(*s, *(s + 1));
	if (check_syntax_help(tok, next))
		return (1);
	if (next == END)
		(print_error(UNEXPECTED_TOK, NULL, INCORRECT_USAGE, 0),
			ft_printf(" `newline'\n"));
	else if (next == AND || next == OR || next == APPEND || next == HEREDOC)
		(print_error(UNEXPECTED_TOK, NULL, INCORRECT_USAGE, 0),
			ft_printf(" `%c%c'\n", *s, *(s + 1)));
	else
		(print_error(UNEXPECTED_TOK, NULL, INCORRECT_USAGE, 0),
			ft_printf(" `%c'\n", *s));
	return (0);
}
