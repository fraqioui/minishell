/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:18:14 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 10:29:35 by fraqioui         ###   ########.fr       */
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
	char	*save;
	ssize_t	l;

	l = calc_len(s);
	new = malloc(sizeof(char) * (l + 1));
	if (!new)
		return (malloc_error(errno));
	l = 0;
	save = s;
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
	return (free(save), new);
}

static	void	eliminate_quotes_phase(char **args)
{
	char	*s;

	while (*args)
	{
		s = new_cmd(*args, NULL);
		*args = s;
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
		return (malloc_error(errno));
	replace_cmd(cmd, s);
	args = fill_cmd(cmd, l, &i, 1);
	args = handle_wildcard_cmd(args);
	eliminate_quotes_phase(args);
	return (free(cmd), free(s), s = NULL, cmd = NULL, args);
}

char	*parse_redir(t_redir *red, char *s, bool *flg)
{
	ssize_t	l;
	char	*cmd;
	ssize_t	i;

	i = 0;
	if (red->tok != HEREDOC)
	{
		l = var_len(s);
		if (l < 0)
			return (NULL);
		cmd = malloc(sizeof(char) * (l + 1));
		if (!cmd)
			return (malloc_error(errno));
		replace_cmd(cmd, s);
	}
	else
	{
		cmd = s;
		s = NULL;
	}
	return (free(s), new_cmd(cmd, flg));
}
