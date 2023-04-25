/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:18:14 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/25 12:44:48 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include"../../headers/minishell.h"
#include<stdio.h>
#include<stdlib.h>

static	int	fill_arr_help(char *ret, char *s, int *i, char c)
{
	int	l;
	int	l_var;

	l = 0;
	s++;
	l++;
	while (*s)
	{
		if (*s == '$')
		{
			l_var = expand_var(s, &i);
			l += l_var;
		}
		if (*s == c)
		{
			s++;
			l++;
			break ;
		}
		ret[(*i)++] = *s++;
		l++;
	}
	return (l);
}

char	*fill_arr(char *ret, char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == 39)
			s += fill_arr_help(ret, s, &i, 39);
		else if (*s == 34)
			s += fill_arr_help(ret, s, &i, 34);
		else
			ret[i++] = *s++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*eliminate_quotes(char **s)
{
	char	**ret;
int l = calc_len(s);
printf("l: %d\n", l);
	ret = malloc(sizeof(char *) * (l + 1));
	if (!ret)
		return (NULL);
	return (fill_arr(ret, s));
}
# include <readline/readline.h>
# include <readline/history.h>
int main()
{
	char *s = readline("$ ");
	printf("%s\n", eliminate_quotes(s));
}
