/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:37:39 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/23 12:40:14 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

t_tree	node_creation(char **cmd)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	if (!node)
	{
		//tree clear
		ft_putstr_fd("allocation failed\n", 2);
		return (NULL);
	}
	node->left = NULL;
	node->right = NULL;
}