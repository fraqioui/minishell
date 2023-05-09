/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve_func_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:55:25 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/08 11:52:06 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	_chdir_(const char *path)
{
	if (!chdir(path))
		return (0);
	print_error(2, "cd", strerror(errno));
	exit_with_status(1);
	return (-1);
}

ssize_t	_write_(int fildes, const char *buf, size_t nbyte)
{
	if (write(fildes, buf, nbyte) < 0)
		return (print_error(2, "write", strerror(errno)),
			exit_with_status(1), -1);
	return (0);
}
