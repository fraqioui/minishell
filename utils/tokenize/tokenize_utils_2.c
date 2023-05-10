/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:33:06 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 16:15:30 by fraqioui         ###   ########.fr       */
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

static	void	check_flg(bool flg, char *s, ssize_t *k)
{
	if (!flg)
		s[(*k) - 1] = 127;
}

char	*cmd_help(char *s, ssize_t l, ssize_t *k, bool flg)
{
	ssize_t	i;
	ssize_t	j;
	char	*ret;

	ret = malloc(sizeof(char) * (l + 1));
	if (!ret)
		return (malloc_error(errno));
	i = 0;
	while (i < l)
	{
		if (s[*k] == 34 || s[*k] == 39)
		{
			j = check_next_quote(&s[(*k) + 1], s[*k]) + i + 1;
			while (i < j)
			{
				ret[i++] = s[(*k)++];
				check_flg(flg, s, k);
			}
		}
		if (s[*k] == 32)
			s[*k] = 127;
		ret[i++] = s[(*k)++];
		check_flg(flg, s, k);
	}
	return (ret[i] = 0, ret);
}

char	**fill_cmd(char *s, ssize_t l, ssize_t *k, bool flg)
{
	char	*ret;
	char	**sp;

	if (l < 0)
		return (NULL);
	ret = cmd_help(s, l, k, flg);
	sp = ft_split(ret, 127);
	return (free(ret), ret = NULL, sp);
}
