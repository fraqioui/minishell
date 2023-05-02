/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:13:23 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 10:12:05 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	print_error(char *mes1, char *mes2, int exit_status, bool flg)
{
	g_gb.exit_st = exit_status;
	ft_putstr_fd("bash: ", 2);
	if (mes1)
		ft_printf("%s", mes1);
	if (mes2)
		ft_printf(" :%s", mes2);
	if (flg)
		ft_putstr_fd("\n", 2);
}
