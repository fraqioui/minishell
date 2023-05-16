/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:48:54 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 14:10:24 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"
#define IN 0
#define OUT 1
#define APPEND 2

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
	the_env = malloc(sizeof(char *) * (l + 1));
	if (!the_env)
		return (malloc_error(errno));
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

static	char	*path_hlp(char **to_sear, char *cmd, bool *flg)
{
	char	*save0;
	char	*save1;
	int		ret;

	*flg = 1;
	while (*to_sear)
	{
		save0 = ft_strjoin(*to_sear, "/");
		save1 = ft_strjoin(save0, cmd);
		ret = _access_(save1, cmd);
		if (!ret)
			return (free(save0), save1);
		else if (ret == 1)
			return (free(save0), free(save1), NULL);
		(free(save0), free(save1));
		to_sear++;
	}
	*flg = 0;
	return (NULL);
}

char	*find_path_help(char **to_sear, char *cmd)
{
	char	*save;
	bool	flg;
	int		ret;

	if (search_c(cmd, '/'))
	{
		ret = _access_(cmd, cmd);
		if (!ret)
			return (ft_strdup(cmd));
		else if (ret == 1)
			return (NULL);
	}
	else
	{
		save = path_hlp(to_sear, cmd, &flg);
		if (flg)
			return (save);
	}
	return (print_error(2, cmd, strerror(ENOENT)),
		exit_with_status(CMD_N_FOUND), NULL);
}
