/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:10:04 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 10:47:07 by fraqioui         ###   ########.fr       */
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
		print_error("fork", strerror(errno), 1, 1);
	return (pid);
}

int	pipe_sc(int ends[2])
{
	int	ret;

	ret = pipe(ends);
	if (!ret)
		return (0);
	print_error("pipe", strerror(errno), 1, 1);
	return (-1);
}

int	dup_2(int filde1, int filde2)
{
	if (dup2(filde1, filde2) > 0)
		return (filde2);
	print_error("dup", strerror(errno), 1, 1);
	return (-1);
}

int	_close_(char *num, ...)
{
	va_list	ptr;

	va_start(ptr, num);
	while (num++)
		if (close(va_arg(ptr, int)) < 0)
			print_error("close", strerror(errno), 1, 1);
	va_end(ptr);
	return (0);
}

int	_open_(const char *path, int oflag, mode_t mode)
{
	int	fd;

	fd = open(path, oflag, mode);
	if (fd)
		return (fd);
	print_error(path, strerror(errno), 1, 1);
	return (-1);
}

int	executing_cmd(t_node *root)
{
	char	**env;

	env = separate_env(g_gb.env);
	execve(find_path(root->cmd[0]), root->cmd, env);
	//free
	if (errno == ENOENT)
		exit(CMD_N_FOUND);
	if (errno == EACCES)
		exit(NOT_EXEC);
	exit(1);
}
