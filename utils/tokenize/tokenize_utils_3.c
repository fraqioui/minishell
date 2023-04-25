/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:04:43 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/18 10:35:01 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	check_spaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	choose_str(char c, int flg)
{
	return ((flg && check_token(c, 0) == NOT)
		|| (!flg && check_token(c, 0) == NOT && !check_spaces(c)));
}

int	not_len(char *s, int i, int flg)
{
	int	l;

	l = 0;
	while (s[i] && choose_str(s[i], flg))
	{
		if (s[i] == 34 || s[i] == 39)
		{
			if (check_next_quote(&s[i + 1], s[i]) == -1)
				return (-1);
			l += check_next_quote(&s[i + 1], s[i]) + 1;
			i += check_next_quote(&s[i + 1], s[i]) + 1;
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
