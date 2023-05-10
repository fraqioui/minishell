/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:13:23 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 08:33:45 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

void	print_error(int n, ...)
{
	va_list	ptr;

	va_start(ptr, n);
	ft_putstr_fd("bash", 2);
	while (n--)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(va_arg(ptr, char *), 2);
	}
	ft_putstr_fd("\n", 2);
	va_end(ptr);
}

void	exit_with_status(int exit_status)
{
	g_gb.exit_st = exit_status;
}

void	*malloc_error(int errnum)
{
	print_error(2, "malloc", strerror(errnum));
	exit_with_status(1);
	exit(1);
}
