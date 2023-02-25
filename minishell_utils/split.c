/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:50:49 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/25 11:22:14 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

char	**free_2d(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static	int	incre(char c, char d)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	else if ((c == '>' && d == '>') || (c == '<'
			&& d == '<') || (c == '|' && d == '|') || (c == '&'
			&& d == '&') || (c == '>' && d == '&'))
		return (0);
	return (2);
}

static int	ft_words(const char *s2)
{
	int	i;
	int	word;
// || && | > < >> << >&
	i = 0;
	word = 0;
	while (s2[i])
	{
		if (incre(s2[i], 0) == 1)
			i++;
		else if (!incre(s2[i], s2[i + 1]))
			i += 2;
		else
		{
			word++;
			while (incre(s2[i], s2[i + 1]) == 2 && s2[i])
				i++;
		}
	}
	return (word);
}

static char	*ft_fillout(const char *s1, int *j)
{
	char	*new;
	size_t	len;
	int		i;

	len = 0;
	while (incre(s1[*j], 0) == 1)
		(*j)++;
	while (!incre(s1[*j], s1[*j + 1]))
			(*j) += 2;
	i = *j;
	while (s1[i] && incre(s1[i], s1[i + 1]) == 2)
	{
		len++;
		i++;
	}
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[*j] && incre(s1[*j], s1[*j + 1]) == 2)
		new[i++] = s1[(*j)++];
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s)
{
	char	**t_arr;
	int		i;
	int		wc;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wc = ft_words(s);
	t_arr = malloc(sizeof(char *) * (wc + 1));
	if (!t_arr)
		return (NULL);
	while (j < wc)
	{
		t_arr[j] = ft_fillout(s, &i);
		if (!t_arr[j])
			return (free_2d(t_arr));
		j++;
	}
	t_arr[j] = 0;
	return (t_arr);
}
