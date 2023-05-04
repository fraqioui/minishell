/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:02:04 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 13:48:01 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

bool	is_identifier(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9') || c == '_');
}

char	*expand_var(char *s, ssize_t *i)
{
	ssize_t	keep;
	char	*var;

	keep = *i;
	while (is_identifier(s[keep]))
		keep++;
	keep -= *i;
	var = get_env(ft_substr(s, *i, keep));
	if (!var)
		return (NULL);
	*i += keep;
	return (var);
}

static	ssize_t	value_len(char *s, ssize_t *i)
{
	char	*var;

	(*i)++;
	var = expand_var(s, i);
	if (!var)
		return (-1);
	return (ft_strlen(var));
}

ssize_t	var_len(char *s)
{
	ssize_t		l;
	ssize_t		i;

	l = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 39)
			l += look_for_quo(s, &i, s[i]);
		else if (s[i] == 34)
			l += inside_quo(s, &i);
		else if (s[i] == '$' && is_identifier(s[i + 1]))
			l += value_len(s, &i);
		else if (s[i] == '$' && (s[i + 1] == 34 || s[i + 1] == 39))
			i++;
		else
		{
			i++;
			l++;
		}
	}
	return (l);
}
