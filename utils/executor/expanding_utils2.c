/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:02:04 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/25 13:46:49 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

// int	var_c(char c)
// {
// 	return ((c >= 32 && c <= 47) || (c >= 58 && c <= 64)
// 		|| (c >= 91 && c <= 94) || c == 96
// 		|| (c <= 123 && c >= 126));
// }

// static	int	look_for_quo(char *s, char c)
// {
// 	int		l;
// 	int		i;
// 	int		l_var;

// 	l = 0;
// 	if (c == 39)
// 	{
// 		while (*s)
// 		{
// 			s++;
// 			if (*s == c)
// 				return (l);
// 			l++;
// 		}
// 	}
// 	else
// 	{
// 		while (s[i])
// 		{
// 			i++;
// 			if (s[i] == '$')
// 			{
// 				l_var = expand_var(s, &i);
// 				if (l_var < 0)
// 					return (-1);
// 				l += l_var;
// 			}
// 			if (s[i] == c)
// 				return (l);
// 			l++;
// 		}		
// 	}
// 	return (0);
// }

// int	calc_len(char *s)
// {
// 	int	l;
// 	int	i;
// 	int	l_var;

// 	l = 0;
// 	while (*s)
// 	{
// 		if (*s == 39)
// 		{
// 			i = look_for_quo(s, 39);
// 			l += i;
// 			s += i + 2;
// 		}
// 		else if (*s == 34)
// 		{
// 			i = look_for_quo(s, 34);
// 			l += i;
// 			s += i + 2;
// 		}
// 		else
// 		{
// 			if (*s == '$')
// 			{
// 				if (*(s + 1) != 39 && *(s + 1) != 34)
// 				{
// 					l_var = expand_var(s, &i);
// 					if (l_var < 0)
// 						return (-1);
// 					l += l_var;
// 				}
// 			}
// 			s++;
// 			l++;
// 		}
// 	}
// 	return (l);
// }

int	is_identifier(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9') || c == '_');
}
// static	int	expand_var(char *s, int *i)
// {
// 	int		keep;
// 	int		l;
// 	char	*var;

// 	keep = *i;
// 	l = 0;
// 	while (s[keep] && !var_c(s[keep]))
// 	{
// 		keep++;
// 		l++;
// 	}
// 	var = getenv(ft_substr(s, i, l));
// 	*i += keep;
// 	if (!var)
// 		return (-1);
// 	return (ft_strlen(var));
// }
int	expand_var(char *s, int *i)
{
	int		keep;
	char	*var;

	keep = *i;
	while (is_identifier(s[keep]))
		keep++;
	keep -= *i;
	var = getenv(ft_substr(s, *i, keep));
	if (!var)
		return (-1);
	return (num_words(var, ' '));
}

void	analy_var(char *s, int *i, int *l)
{
	int	sv;

	while (s[*i])
	{
		if (s[*i] == '$')
		{
			sv = expand_var(s, i);
			if (sv > 1)
				l += sv - 1;
		}
		*i++;
	}
}

int	look_for_quo(char *s)
{
	int	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

void	check_var(char *s, int *l)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s[i] == 39 || s[i] == 34)
			i += look_for_quo(&s[i]);
		else
			analy_var(&s[i], &i, l);
	}
}

int	num_args(char **s)
{
	int	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

int	calc_len(char **s)
{
	int	l;

	l = num_args(s);
	while (*s)
	{
		check_var(*s, &l);
		*s++;
	}
	return (l);
}
