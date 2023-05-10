/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:32:55 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/09 23:08:45 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/minishell.h"

int	update_exit_st(int status)
{
	if (WIFSTOPPED(status))
		return (FATAL_SIGNAL + WSTOPSIG(status));
	if (WIFSIGNALED(status))
	{
		if (FATAL_SIGNAL + WTERMSIG(status) == 130)
			ft_putstr_fd("\n", 2);
		else if (FATAL_SIGNAL + WTERMSIG(status) == 131)
			ft_putstr_fd("Quit: 3\n", 2);
		return (FATAL_SIGNAL + WTERMSIG(status));
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
