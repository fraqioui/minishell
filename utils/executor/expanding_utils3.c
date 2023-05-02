/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:04:30 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/29 09:43:10 by fraqioui         ###   ########.fr       */
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

static	void	fill_between_quo_2(char **ret, char *s, ssize_t *i)
{
	char	*var;

	*(*ret)++ = s[(*i)++];
	while (s[*i])
	{
		if (s[*i] == '$' && is_identifier(s[(*i) + 1]))
		{
			(*i)++;
			var = expand_var(s, i);
			if (!var)
				return ;
			while (*var)
				*(*ret)++ = *var++;
		}
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

	(*i)++;
	var = expand_var(s, i);
	if (!var)
		return ;
	while (*var)
		*(*ret)++ = *var++;
	*(*ret) = '\0';
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
		else
			*ret++ = s[i++];
	}
	*ret = '\0';
}
