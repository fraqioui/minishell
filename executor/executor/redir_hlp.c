/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_hlp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:36:49 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/08 13:12:36 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

int	ret_fd_in(t_node *node)
{
	t_redir	*trav;
	int		fd;

	fd = 0;
	trav = node->redirections;
	while (trav)
	{
		if (trav->tok == IN)
		{
			if (fd)
				close(fd);
			fd = _open_(trav->file, O_RDONLY, 00644);
		}
		else if (trav->tok == HEREDOC)
		{
			if (fd)
				close(fd);
			fd = trav->fd;
		}
		if (fd < 0)
			return (-1);
		trav = trav->rchild;
	}
	return (node->fd[0] = fd, 0);
}

int	ret_fd_out(t_node *node)
{
	t_redir	*trav;
	int		fd;

	fd = 1;
	trav = node->redirections;
	while (trav)
	{
		if (trav->tok == OUT)
		{
			if (fd != 1)
				close(fd);
			fd = _open_(trav->file, (O_CREAT | O_WRONLY | O_TRUNC), 00644);
		}
		else if (trav->tok == APPEND)
		{
			if (fd != 1)
				close(fd);
			fd = _open_(trav->file, (O_CREAT | O_WRONLY | O_APPEND), 00644);
		}
		if (fd < 0)
			return (-1);
		trav = trav->rchild;
	}
	node->fd[1] = fd;
	return (0);
}
