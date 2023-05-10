/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:32:44 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 08:48:27 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	char	**cmd_prepa(char *s, ssize_t *i, ssize_t flg, t_token tok)
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
	return (fill_cmd(s, not_len(s, *i, flg), i, flg));
}

bool	check_tok_syntax(t_token tok, char *s, ssize_t *i, ssize_t *par)
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
		ft_printf("bash: syntax error near unexpected token `)'\n");
		exit_with_status(INCORRECT_USAGE);
		return (0);
	}
	while (check_spaces(s[*i]))
		(*i)++;
	if (!check_syntax(tok, &s[*i]))
		return (0);
	return (1);
}

static	void	incre(char *s, ssize_t *i)
{
	ssize_t	l;

	l = not_len(s, *i, 1);
	while (l--)
		(*i)++;
}

t_node	*which_token_2(char	*s, t_token tok, ssize_t *i)
{
	ssize_t	save;
	char	*str;
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
	save = not_len(s, *i, 1);
	if (save < 0)
		return (NULL);
	str = ft_substr(s, *i, save);
	if (!str)
		return (NULL);
	return (incre(s, i), node_creation_cmd(str, redir, NOT, 0));
}
