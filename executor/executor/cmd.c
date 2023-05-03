/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:29 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/03 10:39:29 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	bool	is_builtin(char **cmd)
{
	if (!ft_memcmp("cd", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_cd_(cmd), true);
	if (!ft_memcmp("echo", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_echo_(cmd), true);
	if (!ft_memcmp("env", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_env_(), true);
	if (!ft_memcmp("exit", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_exit_(cmd), true);
	if (!ft_memcmp("export", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_export_(cmd), true);
	if (!ft_memcmp("pwd", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_pwd_(), true);
	if (!ft_memcmp("unset", cmd[0], ft_strlen(cmd[0]) + 1))
		return (_unset_(cmd), true);
	return (false);
}

void	exec_cmd(t_node *root)
{
	pid_t	pid;
	int		status;
//redir before builtin
	if (!_expanding_(root))
		return ;
	if (root->redirections)
	{
		handle_redirections(root);
		if (dup_2(root->fd[0], STDIN_FILENO) < 0
			|| dup_2(root->fd[1], STDOUT_FILENO) < 0)
			return ;
	}
	if (!is_builtin(root->cmd))
	{
		_signal_middle_exec();
		pid = _fork_();
		if (!pid)
			executing_cmd(root);
		waitpid(pid, &status, WCONTINUED);
	}
}
