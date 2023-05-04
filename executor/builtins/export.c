/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:59 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 11:15:34 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	void	_export_help(char *s)
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
		return (print_error("export", "invalid indentifier", 1, 1));
	_export_var(s, *save);
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

	env = copy_env();
	sort_env(env);
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
}

void	_export_(char **cmd)
{
	if (!cmd[1])
		print_env();
	else
	{
		while (*++cmd)
			_export_help(*cmd);
	}
}

/*
# ENV EXPANSIONS
ENV_SHOW="env | sort | grep -v SHLVL | grep -v _="
EXPORT_SHOW="export | sort | grep -v SHLVL | grep -v _= | grep -v OLDPWD"
exec_test 'export ='
exec_test 'export 1TEST= ;' $ENV_SHOW
exec_test 'export TEST ;' $EXPORT_SHOW
exec_test 'export ""="" ; ' $ENV_SHOW
exec_test 'export TES=T="" ;' $ENV_SHOW
exec_test 'export TE+S=T="" ;' $ENV_SHOW
exec_test 'export TEST=LOL ; echo $TEST ;' $ENV_SHOW
exec_test 'export TEST=LOL ; echo $TEST$TEST$TEST=lol$TEST'
exec_test 'export TEST=LOL; export TEST+=LOL ; echo $TEST ;' $ENV_SHOW
exec_test $ENV_SHOW
exec_test $EXPORT_SHOW
exec_test 'export TEST="ls       -l     - a" ; echo $TEST ; $LS ; ' $ENV_SHOW

export ""

unset ""

export test=

export =test

export =

export "==="

export '= = ='
 export "" et unset ""
	export var; export var=test
	 export var ="cat Makefile | grep >"
 export "test=ici"=coucou
	export LOL=lala ROR=rara
 unset LOL ROR
 export "HI= hi"
 export "HI =hi"
 
*/