/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:10:04 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 08:28:59 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"
#define IN 0
#define OUT 1
#define APPEND 2

pid_t	_fork_(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		(print_error(2, "fork", strerror(errno)), exit_with_status(1));
	return (pid);
}

int	pipe_sc(int ends[2])
{
	int	ret;

	ret = pipe(ends);
	if (!ret)
		return (0);
	print_error(2, "pipe", strerror(errno));
	exit_with_status(1);
	return (-1);
}

int	dup_2(int filde1, int filde2)
{
	if (dup2(filde1, filde2) > 0)
		return (filde2);
	print_error(2, "dup", strerror(errno));
	exit_with_status(1);
	return (-1);
}

int	_close_(int n, ...)
{
	va_list	ptr;

	va_start(ptr, n);
	while (n--)
		if (close(va_arg(ptr, int)) < 0)
			(print_error(2, "close", strerror(errno)), exit_with_status(1));
	va_end(ptr);
	return (0);
}

int	_open_(const char *path, int oflag, mode_t mode)
{
	int	fd;

	fd = open(path, oflag, mode);
	if (fd)
		return (fd);
	print_error(2, (char *)path, strerror(errno));
	exit_with_status(1);
	return (-1);
}
