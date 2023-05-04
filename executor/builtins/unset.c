/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:54 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/03 18:31:27 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	void	delete_node(t_env *node, int keep)
{
	if (!keep)
		g_gb.env = g_gb.env->next;
	else
		node->next = node->next->next;
}

void	_unset_(char **cmd)
{
	t_env	*trav;
	t_env	*save;
	int		keep;
//unset many var
	while (*++cmd)
	{
		trav = g_gb.env;
		keep = 0;
		while (trav)
		{
			if (!ft_memcmp(*cmd, trav->var, ft_strlen(*cmd) + 1))
			{
				delete_node(save, keep);
				break ;
			}
			save = trav;
			trav = trav->next;
			keep++;
		}
	}
}
