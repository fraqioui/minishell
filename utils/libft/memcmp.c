/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:58:54 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/01 16:34:07 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

bool	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!(s1 || !s2 || !n))
		return (0);
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

/*
export ""

unset ""

export test=

export =test

export =

export "==="

export '= = ='
*/