/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:08:36 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/30 13:31:29 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

t_token	check_token(char c1, char c2)
{
	if (c1 == '|' && c2 == '|')
		return (OR);
	if (c1 == '&' && c1 == '&')
		return (AND);
	if (c1 == '<' && c2 == '<')
		return (HEREDOC);
	if (c1 == '>' && c2 == '>')
		return (APPEND);
	if (c1 == '(')
		return (LPR);
	if (c1 == ')')
		return (RPR);
	if (c1 == '|')
		return (PIPE);
	if (c1 == '>')
		return (OUT);
	if (c1 == '<')
		return (IN);
	if (!c1)
		return (END);
	return (NOT);
}

static	char	**cmd_prepa(char *s, int *i)
{
	int		l;
	int		save;

	l = 0;
	save = *i;
	while (check_token(s[save], 0) == NOT)
	{
		if (s[save] == 34 || s[save] == 39)
		{
			if (check_next_quote(&s[save + 1]) == -1)
				return (NULL);
			l += check_next_quote(&s[save + 1]) + 1;
			save += check_next_quote(&s[save + 1]) + 1;
		}
		l++;
		save++;
	}
	return (fill_cmd(s, l, i));
}

static	int	check_tok_syntax(t_token tok, char *s, int *i, int *par)
{
	(*i)++;
	if (tok == OR || tok == AND || tok == HEREDOC || tok == APPEND)
		(*i)++;
	else if (tok == LPR)
	{
		if (!*par)
			*par = *i;
		*par = check_rpr(&s[*par], *par) + 1;
		if (*par == -1)
			return (0);
	}
	else if (tok == RPR && ((*i) - 1) > *par)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `)'\n", 2);
		return (0);
	}
	while (check_spaces(s[*i]))
		(*i)++;
	if (!check_syntax(tok, &s[*i]))
		return (0);
	return (1);
}

static	int	which_token_(t_node **head, char *s, int *i, int *par)
{
	t_token	tok;
	t_node	*node;
	char	**str;

	tok = check_token(s[*i], s[(*i) + 1]);
	if (tok != NOT)
	{
		str = NULL;
		if (!check_tok_syntax(tok, s, i, par))
			return (0);
	}
	else
	{
		str = cmd_prepa(s, i);
		if (!str)
			return (0);
	}
	node = node_creation(str, tok);
	if (!node)
		return (0);
	list_build(head, node);
	return (1);
}

t_node	*tokenize(char *s)
{
	t_node	*head;
	int		par;
	int		i;

	par = 0;
	i = 0;
	head = NULL;
	while (s[i])
	{
		if (!which_token_(&head, s, &i, &par))
			return (NULL);
	}
	return (head);
}
