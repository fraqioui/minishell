/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:18:14 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/03 10:37:31 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	ssize_t	calc_len(char *s)
{
	ssize_t	l;

	l = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
		{
			s++;
			continue ;
		}
		s++;
		l++;
	}
	return (l);
}

char	*new_cmd(char *s, bool *flg)
{
	char	*new;
	ssize_t	l;

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
			if (flg)
				*flg = 0;
			continue ;
		}
		new[l++] = *s++;
	}
	new[l] = '\0';
	return (new);
}

static	void	eliminate_quotes_phase(char **args)
{
	while (*args)
	{
		*args = new_cmd(*args, NULL);
		args++;
	}
}

char	**parse_cmd(char *s)
{
	ssize_t	l;
	char	*cmd;
	char	**args;
	ssize_t	i;

	i = 0;
	l = var_len(s);
	if (l < 0)
		return (NULL);
	cmd = malloc(sizeof(char) * (l + 1));
	if (!cmd)
		return (NULL);
	replace_cmd(cmd, s);
	printf("%s\n", cmd);
	args = fill_cmd(cmd, l, &i, 1);
	i = 0;
	while (args[i])
		printf("args: %s\n", args[i++]);
	args = handle_wildcard_cmd(args);
	eliminate_quotes_phase(args);
	i = 0;
	while (args[i])
		printf("%s\n", args[i++]);
	return (args);
}

char	*parse_redir(char *s, bool *flg)
{
	ssize_t	l;
	char	*cmd;
	ssize_t	i;

	i = 0;
	l = var_len(s);
	if (l < 0)
		return (NULL);
	cmd = malloc(sizeof(char) * (l + 1));
	if (!cmd)
		return (NULL);
	replace_cmd(cmd, s);
	return (new_cmd(cmd, flg));
}
