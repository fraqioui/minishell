/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:41:32 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/08 14:32:10 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	bool	check_option(char *s)
{
	if (!*s)
		return (false);
	if (*s == '-' && *(s + 1))
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
	exit_with_status(0);
}
