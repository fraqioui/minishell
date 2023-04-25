/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:29 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/25 10:38:18 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int exec_cmd(t_node *root)
{
	//expanding + eliminate quotes
	if (_expanding_(root) < 0)
		return (-1);
	//checking builtins
	//redirections
	//forking
}
