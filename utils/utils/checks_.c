/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:01:11 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 13:03:20 by fraqioui         ###   ########.fr       */
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
