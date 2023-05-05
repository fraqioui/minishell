/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:48:54 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 14:35:36 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

char	**separate_env(t_env *env)
{
	int		l;
	char	**the_env;
	t_env	*tmp;
	int		i;

	tmp = env;
	l = 0;
	i = 0;
	while (tmp)
	{
		l++;
		tmp = tmp->next;
	}
	the_env = _malloc_(sizeof(char) * (l + 1));
	while (env)
	{
		the_env[i++] = env->env;
		env = env->next;
	}
	the_env[i] = NULL;
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
	{
		if (!access(path, X_OK))
			return (0);
		return (print_error(2, cmd, strerror(errno)),
			exit_with_status(NOT_EXEC), 1);
	}
	else
		return (-1);
}

static	char	*find_path_help(char **to_sear, char *cmd)
{
	char	*save;
	int		ret;

	if (search_c(cmd, '/'))
		return (_access_(cmd, cmd), cmd);
	else
	{
		while (*to_sear)
		{
			save = ft_strjoin(ft_strjoin(*to_sear, "/"), cmd);
			ret = _access_(save, cmd);
			if (!ret)
				return (save);
			else if (ret == 1)
				return (NULL);
			to_sear++;
		}
	}
	return (print_error(2, cmd, strerror(ENOENT)),
		exit_with_status(CMD_N_FOUND), NULL);
}

char	*find_path(char *cmd)
{
	char	**path;

	path = ft_split(get_env("PATH"), ':');
	return (find_path_help(path, cmd));
}
