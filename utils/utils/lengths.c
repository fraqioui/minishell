/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:10:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 16:12:15 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

ssize_t	check_next_quote(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			return (i);
		i++;
		s++;
	}
	print_error(1, "syntax error: unclosed quotes");
	exit_with_status(INCORRECT_USAGE);
	return (-1);
}

ssize_t	check_rpr(char *s, ssize_t i)
{
	while (*s)
	{
		if (*s == ')')
			return (i);
		i++;
		s++;
	}
	print_error(1, "syntax error: unclosed parentheses");
	exit_with_status(INCORRECT_USAGE);
	return (-1);
}

ssize_t	not_len(char *s, ssize_t i, bool flg)
{
	ssize_t	l;
	ssize_t	keep;

	l = 0;
	while (s[i] && choose_str(s[i], flg))
	{
		if (s[i] == 34 || s[i] == 39)
		{
			keep = check_next_quote(&s[i + 1], s[i]);
			if (keep == -1)
				return (-1);
			l += keep + 1;
			i += keep + 1;
		}
		l++;
		i++;
	}
	if (!flg)
	{
		while (check_spaces(s[i++]))
			l++;
	}
	return (l);
}

ssize_t	look_for_quo(char *s, ssize_t *i, char c)
{
	ssize_t	l;

	l = 0;
	while (s[*i])
	{
		(*i)++;
		l++;
		if (s[*i] == c)
		{
			(*i)++;
			l++;
			return (l);
		}
	}
	return (-1);
}

ssize_t	inside_quo(char *s, ssize_t *i)
{
	ssize_t	l;
	char	*var;

	l = 0;
	l++;
	(*i)++;
	while (s[*i])
	{
		if (s[*i] == '$' && (is_identifier(s[(*i) + 1]) || s[(*i) + 1] == '?'))
		{
			(*i)++;
			var = expand_var(s, i);
			if (var)
				l += ft_strlen(var);
		}
		else
		{
			(*i)++;
			l++;
			if (s[(*i) - 1] == 34)
				return (l);
		}
	}
	return (-1);
}
