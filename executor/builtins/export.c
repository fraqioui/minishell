/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:59 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/03 09:23:54 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

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
		lstadd_back_env(&ret, node_creation_env(NULL, env->var, env->value));
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
		ft_printf("%s", env->var);
		ft_putstr_fd("=\"", 1);
		ft_printf("%s", env->value);
		ft_putstr_fd("\"\n", 1);
		env = env->next;
	}
}

static	bool	identifier_front(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
}

static	void	_export_help(char *s)
{
	ssize_t	l;
	ssize_t	index;

	l = 0;
	while (identifier_front(*s++))
		l++;
	if (!l)
		print_error("export", NULL, 1, 1);
	while (is_identifier(*s++))
		l++;
	index = find_c(s);
	lstadd_back_env(&g_gb.env, node_creation_env(s,
			ft_substr(s, 0, index), ft_substr(s, index + 1,
				ft_strlen(s) - index)));
}

void	_export_(char **cmd)
{
	if (!cmd[1])
		print_env();
	else
	{
		while (*cmd)
		{
			cmd++;
			_export_help(*cmd);
		}
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