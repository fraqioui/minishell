/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:32:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 14:10:45 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	_exit_(char **cmd)
{
	if (calc_args(cmd) > 2)
		return (ft_putstr_fd("exit\n", 2),
			print_error("exit", "too many arguments", INCORRECT_USAGE, 1));
	if (calc_args(cmd) == 1)
		exit(0);
	else
		exit(ft_atoi(cmd[1]));
}
