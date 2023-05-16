/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:35 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 14:10:39 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	pid_t	left_side(t_node *root, int ends[2])
{
	pid_t	pd;

	pd = _fork_();
	if (pd < 0)
		return (-1);
	if (pd == 0)
	{
		if (dup_2(ends[WRITE_END], STDOUT_FILENO) < 0)
			return (-1);
		_close_(2, ends[WRITE_END], ends[READ_END]);
		executing(root);
		exit(g_gb.exit_st);
	}
	return (pd);
}

static	pid_t	right_side(t_node *root, int ends[2])
{
	pid_t	pd;

	pd = _fork_();
	if (pd < 0)
		return (-1);
	if (pd == 0)
	{
		if (dup_2(ends[READ_END], STDIN_FILENO) < 0)
			return (-1);
		_close_(2, ends[WRITE_END], ends[READ_END]);
		executing(root);
		exit(g_gb.exit_st);
	}
	return (pd);
}

void	_pipe_(t_node *root)
{
	int		ends[2];
	pid_t	pid_read;
	pid_t	pid_write;
	int		status;

	if (pipe_sc(ends) < 0)
		return ;
	pid_write = left_side(root->lchild, ends);
	if (pid_write < 0)
		return ;
	pid_read = right_side(root->rchild, ends);
	if (pid_read < 0)
		return ;
	_close_(2, ends[READ_END], ends[WRITE_END]);
	waitpid(pid_write, &status, 0);
	waitpid(pid_read, &status, 0);
	exit_with_status(update_exit_st(status));
}
