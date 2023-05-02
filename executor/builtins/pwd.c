/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:51:26 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 11:56:32 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	_pwd_(void)
{
	char	s[PATH_MAX];

	if (!getcwd(s, PATH_MAX))
	{
		perror("bash: pwd");
		return ;
	}
	ft_putstr_fd(getcwd(s, PATH_MAX), 1);
	ft_putstr_fd("\n", 1);
}
