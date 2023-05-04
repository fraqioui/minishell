/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:41:32 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/04 13:52:29 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	bool	check_option(char *s)
{
	if (*s == '-')
	{
		s++;
		while (*s == 'n')
			s++;
	}
	if (*s)
		return (false);
	return (true);
}

void	_echo_(char **cmd)
{
	bool	flg;

	cmd++;
	flg = false;
	while (*cmd && check_option(*cmd))
	{
		flg = true;
		cmd++;
	}
	while (*cmd)
	{
		ft_putstr_fd(*cmd++, 1);
		if (*cmd)
			ft_putstr_fd(" ", 1);
	}
	if (!flg)
		ft_putstr_fd("\n", 1);
}
