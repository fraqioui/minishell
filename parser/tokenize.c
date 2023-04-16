/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:08:36 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/16 15:52:36 by fraqioui         ###   ########.fr       */
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

static	int	check_true(t_token tok)
{
	return (tok == NOT || tok == IN || tok == OUT
		|| tok == APPEND || tok == HEREDOC);
}

static	int	choose_str(char c, int flg)
{
	return ((flg && check_token(c, 0) == NOT)
		|| (!flg && check_token(c, 0) == NOT && !check_spaces(c)));
}

static	int	not_len(char *s, int i, int flg)
{
	int	l;

	l = 0;
	while (check_spaces(s[i]))
	{
		i++;
		l++;
	}
	while (s[i] && choose_str(s[i], flg))
	{
		if (s[i] == 34 || s[i] == 39)
		{
			if (check_next_quote(&s[i + 1]) == -1)
				return (-1);
			l += check_next_quote(&s[i + 1]) + 1;
			i += check_next_quote(&s[i + 1]) + 1;
		}
		l++;
		i++;
	}
	if (!flg)
	{
		while (check_spaces(s[i]))
		{
			i++;
			l++;
		}
	}
	return (l);
}

static	char	**cmd_prepa(char *s, int *i, int flg, t_token tok)
{
	printf("--%d\n", *i);
	if (!flg)
	{
		s[*i] = 127;
		(*i)++;
		if (tok == HEREDOC || tok == APPEND)
		{
			s[*i] = 127;
			(*i)++;
		}
	}
	printf("len: %d\n",  not_len(s, *i, flg));
	return (fill_cmd(s, not_len(s, *i, flg), i, flg));
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

static	t_node	*which_token_2(char	*s, t_token tok, int *i)
{
	int		save;
	char	**str;
	t_redir	*redir;

	save = *i;
	redir = NULL;
	printf("i: %d\n", *i);
	while (check_true(tok))
	{
		printf("tok: %d\t%d\n", tok, check_true(tok));
		if (tok != NOT)
		{
			puts("2\n");
			if (!list_build_redir(&redir,
					node_creation_redir(cmd_prepa(s, &save, 0, tok)[0], tok)))
				return (0);
			printf("1save: %d\t%c\n", save, s[save]);
			puts("3\n");
		}
		else
			save++;
		tok = check_token(s[save], s[save + 1]);
		printf("save: %d\t%c\n", save, s[save]);
		printf("s: %s\n", s);
	}
	printf("c: %c\n", s[save]);
	str = cmd_prepa(s, i, 1, NOT);
	int v = -1;
	while (str[++v])
		printf("--%s--\n", str[v]);
	if (!str)
		return (0);
	return (node_creation_cmd(str, redir, NOT, 0));
}

static	int	which_token_1(t_node **head, char *s, int *i, int *par)
{
	t_token	tok;
	t_node	*node;

	tok = check_token(s[*i], s[(*i) + 1]);
	printf("tok: %d\n", tok);
	if (!check_true(tok))
	{
		if (!check_tok_syntax(tok, s, i, par))
			return (0);
		node = node_creation_cmd(NULL, NULL, tok, check_pre(tok));
	}
	else
		node = which_token_2(s, tok, i);
	if (!node)
		return (0);
	list_build_cmd(head, node);
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
		if (!which_token_1(&head, s, &i, &par))
			return (NULL);
	}
	puts("here\n");
	while (head)
	{
		printf("tok: %d\t", head->tok);
		if (head->cmd)
		{
			printf("s: ");
			int i = -1;
			while (head->cmd[++i])
				printf("-%s-\t", head->cmd[i]);
		}
		if (head->redirections)
		{
			printf("redirections: ");
			while (head->redirections)
			{
				printf("%d\t-%s-\t", head->redirections->tok, head->redirections->file);
				head->redirections = head->redirections->rchild;
			}
		}
		puts("\n");
		head = head->rchild;
	}
	exit(0);
	return (head);
}
