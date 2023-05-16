/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:25:04 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 17:12:31 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

char	*get_env(const char *name)
{
	int		i;
	t_env	*tmp;

	if (!g_gb.env || !name)
		return (NULL);
	i = 0;
	tmp = g_gb.env;
	while (tmp)
	{
		if (!ft_memcmp(name, tmp->var, ft_strlen(name) + 1))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
