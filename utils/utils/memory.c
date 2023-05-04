/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:09:57 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 13:14:14 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	*__malloc__(size_t size)
{
	void	*ptr;

	ptr = _malloc_(size);
	if (!ptr)
		return (print_error("_malloc_", strerror(errno)),
			exit_with_status(1), NULL);
	lstadd_front_mem(&g_gb.mem, node_creation_mem(ptr));
	return (ptr);
}

void	get_mem_back(void)
{
	t_mem	*trav;

	trav = g_gb.mem;
	while (trav)
	{
		free(trav->ptr);
		trav = trav->next;
	}
	trav = g_gb.mem;
	while (trav)
	{
		free(trav);
		trav = trav->next;
	}
}
