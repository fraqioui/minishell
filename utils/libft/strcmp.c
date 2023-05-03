/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:43:54 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 21:29:06 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	s1_l;
	size_t	s2_l;
	size_t	i;
	size_t	j;

	if (!(s1 || s2))
		return (0);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	i = 0;
	j = 0;
	while (i <= s1_l && j <= s2_l)
	{
		if (s1[i] != s2[j])
			return ((unsigned char) s1[i] - s2[j]);
		i++;
		j++;
	}
	return (0);
}
