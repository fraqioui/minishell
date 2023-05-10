/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:51:20 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 22:09:58 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	char	*eliminate_plus(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * ft_strlen(s));
	if (!ret)
		return (malloc_error(errno));
	while (*s)
	{
		if (*s == '+')
			s++;
		ret[i++] = *s++;
	}
	ret[i] = '\0';
	return (ret);
}

static	void	env_hlp(t_env *trav, char *s, ssize_t index, char c)
{
	char	*tmp;
	char	*save;

	if (c == '+')
	{
		s = eliminate_plus(s);
		tmp = ft_substr(s, index + 1, ft_strlen(s) - index);
		save = ft_strjoin(trav->value, tmp);
		(free(trav->value), free(tmp), free(s), trav->value = save);
	}
	else
	{
		save = ft_substr(s, index + 1, ft_strlen(s) - index);
		free(trav->value);
		trav->value = save;
	}
	save = ft_strjoin(trav->var, "=");
	(free(trav->env), trav->env = ft_strjoin(save, trav->value));
	free(trav->var);
	free(save);
}

static	bool	access_env(char *var, char *s, ssize_t index, char c)
{
	t_env	*trav;

	trav = g_gb.env;
	while (trav)
	{
		if (!ft_memcmp(var, trav->var, ft_strlen(var) + 1))
		{
			if (c)
				env_hlp(trav, s, index, c);
			else
				(free(trav->var), trav->var = NULL);
			return (trav->var = var, true);
		}
		trav = trav->next;
	}
	return (false);
}

static	void	_export_var_help(char *s, char *var, char c, ssize_t index)
{
	if (c == '=')
		lstadd_back_env(&g_gb.env, node_creation_env(ft_strdup(s),
				var, ft_substr(s, index + 1,
					ft_strlen(s) - index)));
	else if (c == '+')
	{
		s = eliminate_plus(s);
		lstadd_back_env(&g_gb.env, node_creation_env(s,
				var, ft_substr(s, index + 1,
					ft_strlen(s) - index)));
	}
	else
		(lstadd_back_env(&g_gb.env,
				node_creation_env(ft_strdup(var), ft_strdup(var), NULL)),
			free(var));
}

void	_export_var(char *s, char c)
{
	ssize_t	index;
	char	*var;

	index = 0;
	if (c)
	{
		index = find_c(s, c);
		var = ft_substr(s, 0, index);
	}
	else
		var = ft_strdup(s);
	if (access_env(var, s, index, c))
		;
	else
		_export_var_help(s, var, c, index);
}
