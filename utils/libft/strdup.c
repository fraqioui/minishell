/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:22:36 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 13:52:00 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	size_t	n;
	int		i;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	i = 0;
	arr = _malloc_(sizeof(char) * (n + 1));
	if (!arr)
		return (NULL);
	while (n--)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
