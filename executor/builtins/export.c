/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:59 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 20:30:16 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	bool	_export_help(char *s)
{
	ssize_t	l;
	char	*save;

	l = 0;
	save = s;
	while (identifier_front(*save))
	{
		l++;
		save++;
	}
	while (is_identifier(*save))
		save++;
	if (!l || (!(*save == '+' && *(save + 1) == '=') && *save != '=' && *save))
		return (print_error(3, "export", s, "not a valid identifier"),
			exit_with_status(1), false);
	return (_export_var(s, *save), true);
}

static	void	sort_env(t_env *env)
{
	t_env	*save;
	char	*s;

	while (env)
	{
		save = env->next;
		while (save)
		{
			if (strcmp(env->var, save->var) > 0)
			{
				s = env->var;
				env->var = save->var;
				save->var = s;
				s = env->env;
				env->env = save->env;
				save->env = s;
				s = env->value;
				env->value = save->value;
				save->value = s;
			}
			save = save->next;
		}
		env = env->next;
	}
}

static	t_env	*copy_env(void)
{
	t_env	*env;
	t_env	*ret;

	env = g_gb.env;
	ret = NULL;
	while (env)
	{
		lstadd_back_env(&ret, node_creation_env
			(env->env, env->var, env->value));
		env = env->next;
	}
	return (ret);
}

static	void	print_env(void)
{
	t_env	*env;
	t_env	*save;

	env = copy_env();
	sort_env(env);
	save = env;
	while (env)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->var, 1);
		if (find_c(env->env, '=') != -1)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(env->value, 1);
			ft_putstr_fd("\"\n", 1);
		}
		else
			ft_putstr_fd("\n", 1);
		env = env->next;
	}
	_free_(save);
}

void	_export_(char **cmd)
{
	if (!cmd[1])
		print_env();
	else
	{
		while (*++cmd)
			if (!_export_help(*cmd))
				return ;
	}
	exit_with_status(0);
}
