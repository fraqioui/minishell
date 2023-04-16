/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:28:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/13 13:40:07 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	_cd_(char *path, char **env)
{
	char	s[PATH_MAX];

	if (!path)
	{
		path = getenv("HOME");
		if (!path)
		{
			ft_putstr_fd("bash: cd: HOME not set\n", 2);
			return (-1);
		}
	}
	if (getcwd(s, PATH_MAX) < 0 && errno == ENOENT)
	{
		ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot \
		access parent directories: No such file or directory\n", 2);
		return (-1);
	}
	if (chdir(path) < 0)
	{
		ft_printf("bash: cd: %s: ", path);
		perror("");
		return (-1);
	}
	return (0);
}
