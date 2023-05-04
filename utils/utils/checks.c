/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:10:07 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 14:14:40 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

bool	check_tok(char *s)
{
	t_token	tok;

	tok = check_token(s[0], s[1]);
	if (tok == OR || tok == AND)
	{
		ft_printf("bash: %s `%c%c'\n", UNEXPECTED_TOK, s[0], s[1]);
		exit_with_status(INCORRECT_USAGE);
		return (0);
	}
	else if (tok == PIPE || tok == RPR)
	{
		ft_printf("bash: %s `%c'\n", UNEXPECTED_TOK, s[0]);
		exit_with_status(INCORRECT_USAGE);
		return (0);
	}
	return (1);
}

bool	check_true(t_token tok)
{
	return (tok == NOT || tok == IN || tok == OUT
		|| tok == APPEND || tok == HEREDOC);
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

bool	check_spaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

bool	choose_str(char c, bool flg)
{
	return ((flg && check_token(c, 0) == NOT)
		|| (!flg && check_token(c, 0) == NOT && !check_spaces(c)));
}
