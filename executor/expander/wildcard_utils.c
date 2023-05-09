/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:08:27 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 10:35:31 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	checking(char *s, int *flg)
{
	ssize_t	i;

	i = 0;
	*flg = -1;
	while (s[i])
	{
		if (s[i] == 39 || s[i] == 34)
		{
			*flg = 0;
			look_for_quo(s, &i, s[i]);
			continue ;
		}
		else if (s[i] == '*')
		{
			*flg = 1;
			i++;
			break ;
		}
		i++;
	}
}

static	void	check_ptt_hlp(char *d_name, char *pattern, int *j, int *i)
{
	int	index_d;
	int	index_ptt;

	index_ptt = -1;
	index_d = -1;
	while (d_name[*i])
	{
		if (d_name[*i] == pattern[*j])
		{
			(*i)++;
			(*j)++;
		}
		else if (pattern[*j] == '*')
		{
			index_d = *i;
			index_ptt = (*j)++;
		}
		else if (index_ptt != -1)
		{
			*j = 1 + index_ptt;
			*i = 1 + index_d++;
		}
		else
			break ;
	}
}

bool	check_patterns(char *d_name, char *pattern)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	check_ptt_hlp(d_name, pattern, &j, &i);
	if (i != (int)ft_strlen(d_name))
		return (false);
	while (pattern[j] == '*')
		j++;
	if (j == (int)ft_strlen(pattern))
		return (true);
	return (false);
}

void	calc_files(char *s, ssize_t *l)
{
	DIR				*dp;
	struct dirent	*entry;
	ssize_t			save;

	dp = opendir(".");
	entry = readdir(dp);
	save = *l;
	while (entry)
	{
		if (*s != '.')
		{
			if (entry->d_name[0] != '.' && check_patterns(entry->d_name, s))
				(*l)++;
		}
		else
		{
			if (check_patterns(entry->d_name, s))
					(*l)++;
		}
		entry = readdir(dp);
	}
	if (save == *l)
		(*l)++;
	closedir(dp);
}
