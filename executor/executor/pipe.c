/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:31:35 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/03 10:09:37 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

static	void	left_side(t_node *root, int ends[2])
{
	if (dup_2(ends[WRITE_END], STDOUT_FILENO) < 0)
		return ;
	_close_("ab", ends[WRITE_END], ends[READ_END]);
	executing(root);
}

static	void	right_side(t_node *root, int ends[2])
{
	if (dup_2(ends[READ_END], STDOUT_FILENO) < 0)
		return ;
	_close_("ab", ends[WRITE_END], ends[READ_END]);
	executing(root);
}

void	_pipe_(t_node *root)
{
	int		ends[2];
	pid_t	pid[2];
	int		status;

	if (pipe_sc(ends) < 0)
		return ;
	pid[0] = _fork_();
	if (!pid[0])
		left_side(root->lchild, ends);
	pid[1] = _fork_();
	if (!pid[1])
		right_side(root->rchild, ends);
	waitpid(pid[0], &status, WCONTINUED);
	waitpid(pid[1], &status, WCONTINUED);
}
