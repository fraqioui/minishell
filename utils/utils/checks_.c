/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:01:11 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 09:09:57 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

ssize_t	calc_args(char **av)
{
	ssize_t	i;

	i = 0;
	while (*av++)
		i++;
	return (i);
}

bool	identifier_front(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
}

void	should_expnd(bool *flg)
{
	if (flg)
		*flg = 0;
}
