/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:54 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/03 09:25:04 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	delete_node(t_env *node, int keep)
{
	if (!keep)
		g_gb.env = g_gb.env->next;
	else
		node = node->next;
}

void	_unset_(char **cmd)
{
	t_env	*trav;
	int		keep;

	keep = 0;
	while (*cmd)
	{
		trav = g_gb.env;
		while (trav)
		{
			if (!ft_memcmp(*cmd, trav->var, ft_strlen(*cmd) + 1))
				delete_node(trav, keep);
			trav = trav->next;
		}
		keep++;
		cmd++;
	}
}
