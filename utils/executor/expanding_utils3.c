/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:04:30 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 09:49:54 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	void	fill_between_quo_1(char **ret, char *s, ssize_t *i)
{
	while (s[*i])
	{
		*(*ret)++ = s[(*i)++];
		if (s[*i] == 39)
		{
			*(*ret)++ = s[(*i)++];
			*(*ret) = '\0';
			return ;
		}
	}
}

static	void	quo_2_hlp(char **ret, ssize_t *i, char *s)
{
	char	*var;
	char	*tmp;

	(*i)++;
	var = expand_var(s, i);
	tmp = var;
	if (!var)
		return ;
	while (*var)
		*(*ret)++ = *var++;
	free(tmp), tmp = NULL;
}

static	void	fill_between_quo_2(char **ret, char *s, ssize_t *i)
{
	*(*ret)++ = s[(*i)++];
	while (s[*i])
	{
		if (s[*i] == '$' && is_identifier(s[(*i) + 1]))
			quo_2_hlp(ret, i, s);
		else if (s[*i] == 34)
		{
			*(*ret)++ = s[(*i)++];
			*(*ret) = '\0';
			return ;
		}
		else
			*(*ret)++ = s[(*i)++];
		*(*ret) = '\0';
	}	
}

static	void	replace_var(char **ret, char *s, ssize_t *i)
{
	char	*var;
	char	*tmp;

	(*i)++;
	var = expand_var(s, i);
	tmp = var;
	if (!var)
		return ;
	while (*var)
		*(*ret)++ = *var++;
	*(*ret) = '\0';
	(free(tmp), tmp = NULL);
}

void	replace_cmd(char *ret, char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 39)
			fill_between_quo_1(&ret, s, &i);
		else if (s[i] == 34)
			fill_between_quo_2(&ret, s, &i);
		else if (s[i] == '$' && is_identifier(s[i + 1]))
			replace_var(&ret, s, &i);
		else if (s[i] == '$' && (s[i + 1] == 34 || s[i + 1] == 39))
			i++;
		else
			*ret++ = s[i++];
	}
	*ret = '\0';
}
