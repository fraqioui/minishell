/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:12:31 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/28 16:36:18 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) <= start + len)
		substr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static	int	ft_search(char c, char const *from)
{
	while (*from)
	{
		if (*from == c)
			return (1);
		from++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	first;
	int	last;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1) - 1;
	while (s1[first] && ft_search(s1[first], set) == 1)
		first++;
	while (last >= first && ft_search(s1[last], set) == 1)
		last--;
	if (last == -1)
		return (ft_substr(s1, first, 0));
	else
		return (ft_substr(s1, first, (last - first + 1)));
}
