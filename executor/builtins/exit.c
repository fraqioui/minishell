/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:32:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 14:07:44 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	bool	is_digit(char *s)
{
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (false);
		s++;
	}
	return (true);
}

void	_exit_(char **cmd)
{
	if (cmd[1] && !is_digit(cmd[1]))
		(ft_putstr_fd("exit\n", 2), print_error(3, "exit", cmd[1],
				"numeric argument required"), exit_with_status(255), exit(-1));
	if (calc_args(cmd) > 2)
		return (ft_putstr_fd("exit\n", 2),
			print_error(2, "exit", "too many arguments"),
			exit_with_status(INCORRECT_USAGE));
	if (calc_args(cmd) == 1)
		exit(0);
	else
		exit(ft_atoi(cmd[1]));
}
