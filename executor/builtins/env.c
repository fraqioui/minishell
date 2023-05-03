/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:32:04 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 14:07:10 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	_env_(void)
{
	t_env	*trav;

	trav = g_gb.env;
	while (trav)
	{
		ft_printf("%s\n", trav->env);
		trav = trav->next;
	}
}
