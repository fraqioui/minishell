/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:38:39 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 23:38:02 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

char	**ft_alloc_fail(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	return (NULL);
}

int	num_words(const char *s2, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s2[i])
	{
		if (s2[i] == c)
			i++;
		else
		{
			word++;
			while (s2[i] != c && s2[i])
				i++;
		}
	}
	return (word);
}

static char	*ft_fillout(const char *s1, int *j, char c)
{
	char	*new;
	size_t	len;
	int		i;

	len = 0;
	while (s1[*j] == c)
		(*j)++;
	i = *j;
	while (s1[i] && s1[i] != c)
	{
		len++;
		i++;
	}
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (malloc_error(errno));
	i = 0;
	while (s1[*j] && s1[*j] != c)
		new[i++] = s1[(*j)++];
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**t_arr;
	int		i;
	int		wc;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wc = num_words(s, c);
	t_arr = malloc(sizeof(char *) * (wc + 1));
	if (!t_arr)
		return (malloc_error(errno));
	while (j < wc)
	{
		t_arr[j] = ft_fillout(s, &i, c);
		if (!t_arr[j])
			return (ft_alloc_fail(t_arr));
		j++;
	}
	t_arr[j] = 0;
	return (t_arr);
}
