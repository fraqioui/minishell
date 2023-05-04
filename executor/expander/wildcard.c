/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:30:11 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 13:14:14 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	void	calc_files(char *s, ssize_t *l)
{
	DIR				*dp;
	struct dirent	*entry;
	ssize_t			save;

	dp = opendir(".");
	entry = readdir(dp);
	save = *l;
	while (entry)
	{
		if (check_patterns(entry->d_name, s))
			(*l)++;
		entry = readdir(dp);
	}
	if (save == *l)
		(*l)++;
	closedir(dp);
}

static	ssize_t	new_args_l(char **args)
{
	int		flg;
	ssize_t	l;

	l = 0;
	while (*args)
	{
		checking(*args, &flg);
		if (flg == 1)
			calc_files(*args, &l);
		else
			l++;
		args++;
	}
	return (l);
}

static	void	_scan_dir_(char **new, char *args, ssize_t *index)
{
	DIR				*dp;
	struct dirent	*entry;
	bool			flg;

	flg = 0;
	dp = opendir(".");
	entry = readdir(dp);
	while (entry)
	{
		if (check_patterns(entry->d_name, args))
		{
			new[(*index)++] = ft_strdup(entry->d_name);
			flg++;
		}
		entry = readdir(dp);
	}
	if (!flg)
		new[(*index)++] = args;
	closedir(dp);
}

static	void	expand_wild(char **new, char **args)
{
	int		flg;
	ssize_t	i;

	i = 0;
	while (*args)
	{
		checking(*args, &flg);
		if (flg == 1)
			_scan_dir_(new, *args++, &i);
		else
			new[i++] = *args++;
	}
	new[i] = NULL;
}

char	**handle_wildcard_cmd(char **args)
{
	ssize_t	l;
	char	**new;

	l = new_args_l(args);
	new = _malloc_(sizeof(char *) * (l + 1));
	expand_wild(new, args);
	return (new);
}
