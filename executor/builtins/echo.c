/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:41:32 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 14:36:19 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	bool	check_option(char *s)
{
	if (*s == '-')
	{
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
	while (check_option(*cmd++))
		flg = true;
	while (*cmd)
	{
		ft_printf("%s", *cmd);
		if (*++cmd)
			ft_putstr_fd(" ", 1);
	}
	if (!flg)
		ft_putstr_fd("\n", 1);
}
