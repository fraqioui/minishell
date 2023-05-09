/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:28:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 09:43:47 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	void	cd_err(void)
{
	ft_putstr_fd("cd: error retrieving current directory: getcwd: ", 2);
	ft_putstr_fd("cannot access parent directories: ", 2);
	ft_putstr_fd("No such file or directory\n", 2);
	exit_with_status(1);
}

static	char	*pmsg(void)
{
	char	*path;

	path = get_env("HOME");
	if (!path)
	{
		ft_putstr_fd("bash: cd: HOME not set\n", 2);
		exit_with_status(1);
		return (NULL);
	}	
	return (path);
}

void	_cd_(char **cmd)
{
	char	s[PATH_MAX];
	char	new[PATH_MAX];
	char	*path;
	char	*old_pwd;

	if (!cmd[1])
		path = pmsg();
	else
		path = cmd[1];
	if (!path)
		return ;
	old_pwd = getcwd(s, PATH_MAX);
	if (_chdir_(path) < 0)
		return ;
	path = getcwd(new, PATH_MAX);
	if (!path && errno == ENOENT)
		return (cd_err());
	if (!update_pwd(path) || !update_oldpwd(old_pwd))
		return ;
	exit_with_status(0);
}
