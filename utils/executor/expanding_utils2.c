/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:02:04 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/28 13:46:58 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	is_identifier(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9') || c == '_');
}

char	*expand_var(char *s, int *i)
{
	int		keep;
	char	*var;

	keep = *i;
	while (is_identifier(s[keep]))
		keep++;
	keep -= *i;
	var = getenv(ft_substr(s, *i, keep));
	if (!var)
		return (NULL);
	*i += keep;
	printf("var: %s\n", var);
	return (var);
}

int	look_for_quo(char *s, int *i, char c)
{
	int	l;

	l = 0;
	while (s[*i])
	{
		(*i)++;
		l++;
		if (s[*i] == c)
		{
			(*i)++;
			l++;
			printf("single quo: %d\n", l);
			return (l);
		}
	}
	return (-1);
}

int	inside_quo(char *s, int *i)
{
	int		l;
	char	*var;

	l = 0;
	while (s[*i])
	{
		if (s[*i] == '$' && is_identifier(s[(*i) + 1]))
		{
			(*i)++;
			var = expand_var(s, i);
			if (!var)
				break ;
			l += ft_strlen(var);
		}
		else if (s[*i] == 34)
		{
			(*i)++;
			l++;
			printf("double: %d\n", l);
			return (l);
		}
		else
		{
			(*i)++;
			l++;
		}
	}
	return (-1);
}

int	var_len(char *s)
{
	int			l;
	int			i;
	char		*var;

	l = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 39)
			l += look_for_quo(s, &i, s[i]);
		else if (s[i] == 34)
			l += inside_quo(s, &i);
		else if (s[i] == '$' && is_identifier(s[i + 1]))
		{
			i++;
			var = expand_var(s, &i);
			if (!var)
				return (-1);
			l += ft_strlen(var);
		}
		else
		{
			i++;
			l++;
		}
	}
	printf("last len: %d\n", l);
	return (l);
}
