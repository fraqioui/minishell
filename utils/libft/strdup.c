/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:22:36 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 14:25:30 by fraqioui         ###   ########.fr       */
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
	arr = malloc(sizeof(char) * (n + 1));
	if (!arr)
		return (malloc_error(errno));
	while (n--)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
