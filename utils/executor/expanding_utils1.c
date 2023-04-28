/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:18:14 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/28 14:27:02 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static void	replace_cmd(char *ret, char *s)
{
	static int	i;
	char		*var;

	while (s[i])
	{
		if (s[i] == 39)
		{
			while (s[i])
			{
				*ret++ = s[i++];
				if (s[i] == 39)
				{
					*ret++ = s[i++];
					*ret = '\0';
					break ;
				}
			}
		}
		else if (s[i] == 34)
		{
			*ret++ = s[i++];
			while (s[i])
			{
				if (s[i] == '$' && is_identifier(s[i + 1]))
				{
					i++;
					var = expand_var(s, &i);
					if (!var)
						return ;
					while (*var)
						*ret++ = *var++;
				}
				else if (s[i] == 34)
				{
					*ret++ = s[i++];
					*ret = '\0';
					break ;
				}
				else
					*ret++ = s[i++];
			}
		}
		else if (s[i] == '$' && is_identifier(s[i + 1]))
		{
			i++;
			var = expand_var(s, &i);
			if (!var)
				return ;
			while (*var)
				*ret++ = *var++;
			*ret = '\0';
		}
		else
			*ret++ = s[i++];
	}
	*ret = '\0';
}

static	int calc_len(char *s)
{
	int	l;
	
	l = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
			continue ;
		s++;
		l++;
	}
	return (l);
}

static	char *new_cmd(char *s)
{
	char	*new;
	int		l;

	l = calc_len(s);
	new = malloc(sizeof(char) * (l + 1));
	if (!new)
		return (NULL);
	l = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
		{
			s++;
			continue;
		}
		new[l++] = *s++;
	}
	new[l] = '\0';
	printf("==%s\n", new);
	return (new);
}

static	void	eliminate_quotes_phase(char **args)
{
	while (*args)
	{
		*args = new_cmd(*args);
		args++;
	}
}

char	**eliminate_quotes(char *s)
{
	int		l;
	char	*cmd;
	char	**args;
	int		i;

	i = 0;
	l = var_len(s);
	printf("l: %d\n", l);
	cmd = malloc(sizeof(char) * (l + 1));
	if (!cmd)
		return (NULL);
	replace_cmd(cmd, s);
	printf("%s\n", cmd);
	args = fill_cmd(cmd, l, &i, 1);
	i =0;
	while (args[i])
		printf("%s\n", args[i++]);
	eliminate_quotes_phase(args);
	i =0;
	while (args[i])
		printf("%s\n", args[i++]);
	return (args);
}
