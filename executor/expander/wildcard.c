/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:09:18 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 16:21:43 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

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

static	void	fnl(ssize_t save, char **new, char *args, ssize_t *index)
{
	if (save == *index)
		new[(*index)++] = args;
	else
		free(args);
}

static	void	_scan_dir_(char **new, char *args, ssize_t *index)
{
	DIR				*dp;
	struct dirent	*entry;
	ssize_t			save;

	dp = opendir(".");
	entry = readdir(dp);
	save = *index;
	while (entry)
	{
		if (*args != '.')
		{
			if (entry->d_name[0] != '.' && check_patterns(entry->d_name, args))
				new[(*index)++] = ft_strdup(entry->d_name);
		}
		else
			if (check_patterns(entry->d_name, args))
				new[(*index)++] = ft_strdup(entry->d_name);
		entry = readdir(dp);
	}
	fnl(save, new, args, index);
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
	new = malloc(sizeof(char *) * (l + 1));
	if (!new)
		return (malloc_error(errno));
	expand_wild(new, args);
	return (free(args), new);
}
