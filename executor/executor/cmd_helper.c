/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:48:54 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/03 10:21:14 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

char	**separate_env(t_env *env)
{
	int		l;
	char	**the_env;
	t_env	*tmp;

	tmp = env;
	l = 0;
	while (tmp)
	{
		l++;
		tmp = tmp->next;
	}
	the_env = malloc(sizeof(char) * (l + 1));
	while (env)
	{
		*the_env++ = env->env;
		env = env->next;
	}
	the_env = NULL;
	return (the_env);
}

static	int	search_c(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static	int	_access_(char *path, char *cmd)
{
	if (!access(path, F_OK))
		if (access(path, X_OK))
			return (0);
	print_error(cmd, strerror(errno), NOT_EXEC, 1);
	return (-1);
}

static	char	*find_path_help(char **to_sear, char *cmd)
{
	char	*save;

	if (search_c(cmd, '/'))
		return (_access_(cmd, cmd), cmd);
	else
	{
		while (*to_sear)
		{
			save = ft_strjoin(ft_strjoin(*to_sear, "/"), cmd);
			if (!_access_(save, cmd))
				return (save);
			to_sear++;
		}
	}
	print_error(cmd, strerror(ENOENT), CMD_N_FOUND, 1);
	return (NULL);
}

char	*find_path(char *cmd)
{
	char	**path;

	path = ft_split(get_env("PATH"), ':');
	return (find_path_help(path, cmd));
}
