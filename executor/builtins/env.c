/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:32:04 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/08 14:32:36 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	_env_(void)
{
	t_env	*trav;

	trav = g_gb.env;
	while (trav)
	{
		if (find_c(trav->env, '=') == -1)
		{
			trav = trav->next;
			continue ;
		}
		ft_putstr_fd(trav->env, 1);
		ft_putstr_fd("\n", 1);
		trav = trav->next;
	}
	exit_with_status(0);
}
