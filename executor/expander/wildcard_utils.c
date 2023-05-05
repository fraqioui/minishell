/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:03:55 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 09:08:36 by fraqioui         ###   ########.fr       */
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

static	bool	confirm_pattern(char *d_name, char *pattern, ssize_t size)
{
	if (!pattern)
		return (0);
	return (!ft_memcmp(d_name, pattern, size));
}

static	int	besides_wild(char *s, ssize_t *i)
{
	ssize_t	keep;

	keep = *i;
	while (s[*i])
	{
		if (s[*i] == '*' && !s[(*i) + 1] && !keep)
			return (-1);
		if (s[*i] == '*')
			return (1);
		(*i)++;
	}
	return (0);
}

static	void	save_index(char *file, ssize_t *i, char c)
{
	while (file[*i])
	{
		if (file[*i] == c)
			return ;
		(*i)++;
	}
	*i = -1;
}

bool	check_patterns(char *d_name, char *pattern)
{
	bool	part;
	ssize_t	i;
	ssize_t	save_1;
	ssize_t	save_2;
	char	*new;
	int		keep;

	part = 1;
	i = -1;
	save_2 = 0;
	new = new_cmd(pattern, 0);
	while (new[++i])
	{
		save_1 = i;
		keep = besides_wild(new, &i);
		if (i)
		{
			save_index(d_name, &save_2, new[save_1]);
			if (save_2 < 0)
				return (0);
			if (keep < 0)
			{
				printf("1. %s %s\n", ft_substr(d_name, 0,
								save_2), ft_substr(new, save_1,
								(i - save_1)));
				part = (confirm_pattern(ft_substr(d_name, 0,
								save_2), ft_substr(new, save_1,
								(i - save_1)), (i - save_1)) && part);			
			}
			if (keep)
			{
				printf("1. %s %s\n", ft_substr(d_name, save_2,
								(i - save_1)), ft_substr(new, save_1,
								(i - save_1)));
				part = (confirm_pattern(ft_substr(d_name, save_2,
								(i - save_1)), ft_substr(new, save_1,
								(i - save_1)), (i - save_1)) && part);
			}
			else if (!keep)
			{
				printf("2. %s %s\n", ft_substr(d_name, save_2,
								(ft_strlen(d_name) - save_2)), ft_substr(new, save_1,
								(i - save_1)));
				part = (confirm_pattern(ft_substr(d_name, save_2,
								(ft_strlen(d_name) - save_2)), ft_substr(new, save_1,
								(i - save_1)), (ft_strlen(d_name) - save_2)) && part);
			}
			printf("part: %d\n", part);
			if (!part)
				return (0);
		}
	}
	//free substr
	return (part);
}
