/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:32:56 by fraqioui          #+#    #+#             */
/*   Updated: 2023/03/28 16:36:14 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

size_t	ft_strlen(const char *s)
{
	const char	*end;

	end = s;
	while (*end)
		end++;
	return (end - s);
}