/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:51:20 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 09:46:23 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	char	*eliminate_plus(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	ret = _malloc_(sizeof(char) * ft_strlen(s));
	while (*s)
	{
		if (*s == '+')
			s++;
		ret[i++] = *s++;
	}
	ret[i] = '\0';
	return (ret);
}

bool	identifier_front(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
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
			{
				if (c == '+')
				{
					s = eliminate_plus(s);
					trav->value = ft_strjoin(trav->value, ft_substr
							(s, index + 1, ft_strlen(s) - index));
					(free(s), s = NULL);
				}
				else
					trav->value = ft_substr(s, index + 1, ft_strlen(s) - index);
				trav->env = ft_strjoin(ft_strjoin(ft_strdup(trav->var), ft_strdup("=")),
						ft_strdup(trav->value));
				(free(var), var = NULL);
			}
			return (true);
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
		lstadd_back_env(&g_gb.env, node_creation_env(ft_strdup(s),
				var, ft_substr(s, index + 1,
					ft_strlen(s) - index)));
	}
	else
		lstadd_back_env(&g_gb.env, node_creation_env(s, s, NULL));
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
		var = s;
	if (access_env(var, s, index, c))
		;
	else
		_export_var_help(s, var, c, index);
}
