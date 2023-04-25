/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:33:06 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/18 10:36:05 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

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

int	check_true(t_token tok)
{
	return (tok == NOT || tok == IN || tok == OUT
		|| tok == APPEND || tok == HEREDOC);
}

char	*cmd_help(char *s, int l, int *k, int flg)
{
	int		i;
	int		j;
	char	*ret;

	ret = malloc(sizeof(char) * (l + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < l)
	{
		if (s[*k] == 34 || s[*k] == 39)
		{
			j = check_next_quote(&s[(*k) + 1], s[*k]) + i + 1;
			while (i < j)
			{
				ret[i++] = s[(*k)++];
				if (!flg)
					s[(*k) - 1] = 127;
			}
		}
		if (s[*k] == 32)
			s[*k] = 127;
		ret[i++] = s[(*k)++];
		if (!flg)
			s[(*k) - 1] = 127;
	}
	ret[i] = 0;
	return (ret);
}

char	**fill_cmd(char *s, int l, int *k, int flg)
{
	if (l < 0)
		return (NULL);
	return (ft_split(cmd_help(s, l, k, flg), 127));
}
