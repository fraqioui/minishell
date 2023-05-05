/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:32:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 14:31:17 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	_exit_(char **cmd)
{
	if (calc_args(cmd) > 2)
		return (ft_putstr_fd("exit\n", 2),
			print_error(2, "exit", "too many arguments"),
			exit_with_status(INCORRECT_USAGE));
	if (calc_args(cmd) == 1)
		exit(0);
	else
		exit(ft_atoi(cmd[1]));
}
