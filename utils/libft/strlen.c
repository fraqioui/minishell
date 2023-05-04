/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:32:56 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 11:18:45 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

size_t	ft_strlen(const char *s)
{
	const char	*end;

	if (!s)
		return (-1);
	end = s;
	while (*end)
		end++;
	return (end - s);
}
