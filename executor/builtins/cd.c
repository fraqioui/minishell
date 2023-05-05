/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:28:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 09:18:31 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	void	update_pwd(char **cmd, char *old_pwd)
{
	t_env	*trav;

	trav = g_gb.env;
	while (trav)
	{
		if (!ft_memcmp(trav->var, "PWD", 4))
		{
			trav->value = cmd[1];
			(free(trav->env), trav->env = NULL);
			trav->env = ft_strdup(ft_strjoin(ft_strjoin(trav->var, "="),
						trav->value));
		}
		else if (!ft_memcmp(trav->var, "OLDPWD", 7))
		{
			trav->value = old_pwd;
			(free(trav->env), trav->env = NULL);
			trav->env = ft_strdup(ft_strjoin(ft_strjoin(trav->var, "="),
						trav->value));
		}
		trav = trav->next;
	}
}
//still update pwd oldpwd if they don't exist
//still a test
void	_cd_(char **cmd)
{
	char	s[PATH_MAX];
	char	*path;
	char	*old_pwd;

	if (!cmd[1])
	{
		path = get_env("HOME");
		if (!path)
		{
			ft_putstr_fd("bash: cd: HOME not set\n", 2);
			exit_with_status(1);
			return ;
		}
	}
	old_pwd = getcwd(s, PATH_MAX);
	if (old_pwd < 0 && errno == ENOENT)
	{
		ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot \
		access parent directories: No such file or directory\n", 2);
		exit_with_status(1);
		return ;
	}
	path = cmd[1];
	if (chdir(path) < 0)
		return ;
	update_pwd(cmd, old_pwd);
}
