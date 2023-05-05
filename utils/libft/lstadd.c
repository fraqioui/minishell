/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:48:09 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 08:40:24 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../../headers/minishell.h"

void	lstadd_front_env(t_env **lst, t_env *new)
{
	if (!(lst || new))
		return ;
	if (!*lst)
		*lst = new;
	new->next = *lst;
	*lst = new;
}

void	lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*back;

	if (!lst || !new)
		return ;
	back = *lst;
	if (back)
	{
		while (back->next)
			back = back->next;
		back->next = new;
	}
	else
		*lst = new;
}
