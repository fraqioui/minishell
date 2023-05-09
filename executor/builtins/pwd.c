/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:51:26 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/08 14:33:19 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	_pwd_(void)
{
	char	s[PATH_MAX];

	getcwd(s, PATH_MAX);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\n", 1);
	exit_with_status(0);
}
