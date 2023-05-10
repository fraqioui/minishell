/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:54 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 20:58:50 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	void	delete_node(t_env *node, int keep)
{
	t_env	*save;

	if (!keep)
	{
		save = g_gb.env;
		g_gb.env = g_gb.env->next;
	}
	else
	{
		save = node->next;
		node->next = node->next->next;
	}
	free(save->env);
	free(save->var);
	free(save->value);
	(free(save), save = NULL);
}

static	bool	valid_identifier(char *s)
{
	int	l;

	l = 0;
	while (identifier_front(*s))
	{
		s++;
		l++;
	}
	while (is_identifier(*s))
		s++;
	if (!l || (!(*s == '+' && *(s + 1) == '=') && *s != '=' && *s))
		return (print_error(3, "unset", s, "not a valid identifier"),
			exit_with_status(1), false);
	return (true);
}

void	_unset_(char **cmd)
{
	t_env	*trav;
	t_env	*save;
	int		keep;

	while (*++cmd)
	{
		if (!valid_identifier(*cmd))
			continue ;
		g_gb.exit_st = 0;
		trav = g_gb.env;
		keep = 0;
		while (trav)
		{
			if (!ft_memcmp(*cmd, trav->var, ft_strlen(*cmd) + 1))
			{
				delete_node(save, keep);
				break ;
			}
			save = trav;
			trav = trav->next;
			keep++;
		}
	}
}

void	_free_(t_env *env)
{
	t_env	*keep;

	while (env)
	{
		keep = env;
		env = env->next;
		(free(keep), keep = NULL);
	}
	exit_with_status(0);
}
