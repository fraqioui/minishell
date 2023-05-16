/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_hlp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:39:59 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 10:34:38 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static bool	pwd_hlp(char *pwd, bool *flg)
{
	t_env	*trav;
	char	*save;

	trav = g_gb.env;
	while (trav)
	{
		if (!ft_memcmp(trav->var, "PWD", 4))
		{
			*flg = 1;
			free(trav->value);
			trav->value = ft_strdup(pwd);
			free(trav->env);
			save = ft_strjoin(trav->var, "=");
			if (!save)
				return (malloc_error(errno), false);
			trav->env = ft_strjoin(save, trav->value);
			return (free(save), true);
		}
		trav = trav->next;
	}
	return (false);
}

bool	update_pwd(char *pwd)
{
	t_env	*trav;
	bool	flg;
	char	*save;

	trav = g_gb.env;
	flg = 0;
	save = NULL;
	if (pwd_hlp(pwd, &flg))
		return (true);
	if (!flg)
	{
		save = ft_strjoin("PWD", "=");
		if (!save)
			return (malloc_error(errno), false);
		lstadd_back_env(&g_gb.env, node_creation_env
			(ft_strjoin(save, pwd), ft_strdup("PWD"), ft_strdup(pwd)));
	}
	return (free (save), true);
}

static	bool	oldpwd(char *oldpwd, bool *flg)
{
	t_env	*trav;
	char	*save;

	trav = g_gb.env;
	while (trav)
	{
		if (!ft_memcmp(trav->var, "OLDPWD", 7))
		{
			*flg = 1;
			free(trav->value);
			trav->value = ft_strdup(oldpwd);
			free(trav->env);
			save = ft_strjoin(trav->var, "=");
			if (!save)
				return (malloc_error(errno), false);
			trav->env = ft_strjoin(save, trav->value);
			return (free(save), true);
		}
		trav = trav->next;
	}
	return (false);
}

bool	update_oldpwd(char *old_pwd)
{
	bool	flg;
	char	*save;

	flg = 0;
	save = NULL;
	if (oldpwd(old_pwd, &flg))
		return (true);
	if (!flg)
	{
		save = ft_strjoin("OLDPWD", "=");
		if (!save)
			return (malloc_error(errno), false);
		lstadd_back_env(&g_gb.env, node_creation_env
			(ft_strjoin(save, old_pwd), ft_strdup("OLDPWD"),
				ft_strdup(old_pwd)));
	}
	return (free(save), true);
}
