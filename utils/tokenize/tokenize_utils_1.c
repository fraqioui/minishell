/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:32:44 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/16 20:50:12 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	char	**cmd_prepa(char *s, int *i, int flg, t_token tok)
{
	if (!flg)
	{
		s[*i] = 127;
		(*i)++;
		if (tok == HEREDOC || tok == APPEND)
		{
			s[*i] = 127;
			(*i)++;
		}
		while (check_spaces(s[*i]))
			(*i)++;
		if (!check_syntax(tok, &s[*i]))
			return (NULL);
	}
	return (fill_cmd(s, not_len(s, *i, flg), i, flg));
}

int	check_tok_syntax(t_token tok, char *s, int *i, int *par)
{
	(*i)++;
	if (tok == OR || tok == AND || tok == HEREDOC || tok == APPEND)
		(*i)++;
	else if (tok == LPR)
	{
		if (!*par)
			*par = *i;
		*par = check_rpr(&s[*par], *par) + 1;
		if (!*par)
			return (0);
	}
	else if (tok == RPR && *i > *par)
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

t_node	*which_token_2(char	*s, t_token tok, int *i)
{
	int		save;
	char	**str;
	t_redir	*redir;

	save = *i;
	redir = NULL;
	while (check_true(tok))
	{
		if (tok != NOT)
		{
			if (!list_build_redir(&redir,
					node_creation_redir(cmd_prepa(s, &save, 0, tok), tok)))
				return (0);
		}
		else
			save++;
		tok = check_token(s[save], s[save + 1]);
	}
	str = cmd_prepa(s, i, 1, NOT);
	if (!str)
		return (0);
	return (node_creation_cmd(str, redir, NOT, 0));
}
