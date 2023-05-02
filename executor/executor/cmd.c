/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:29 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/02 11:49:23 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	exec_cmd(t_node *root)
{
	pid_t	pid;
	int		status;

	if (!_expanding_(root))
		return (-1);
	//checking builtins
	handle_redirections(root);
	if (dup_2(root->fd[0], STDIN_FILENO) < 0
		|| dup_2(root->fd[1], STDOUT_FILENO) < 0)
		return (-1);
	_signal_middle_exec();
	pid = _fork_();
	if (!pid)
		executing_cmd(root);
	waitpid(pid, &status, WCONTINUED);
}
