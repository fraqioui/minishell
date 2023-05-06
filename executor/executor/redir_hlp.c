/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_hlp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:36:49 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 11:05:52 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"
#define IN 0
#define OUT 1

int ret_fd_in(t_redir *node)
{
	mode_t	mode;
	int		rwx;
	int		fd;
	
	mode = 00644;
	rwx = (O_CREAT | O_WRONLY | O_APPEND);
	fd = -2;
	while (node)
	{
		if (node->rchild && (node->rchild->tok == IN || node->rchild->tok == APPEND ||
			node->rchild->tok == HEREDOC))
			close(fd);
		if (node->tok == IN)
			fd = _open_(node->file, O_RDONLY, mode);
		else if (node->tok == APPEND)
			fd = _open_(node->file, rwx, mode);
		else if (node->tok == HEREDOC)
			fd = node->fd;
		if (fd < 0)
			return (-1);
		node = node->rchild;
	}
	return (fd);
}

int ret_fd_out(t_redir *node)
{
	mode_t	mode;
	int		rwx;
	int		fd;

	mode = 00644;
	rwx = (O_CREAT | O_WRONLY | O_TRUNC);
	fd = -2;
	while (node)
	{
		if (node->rchild && node->rchild->tok == OUT)
			close(fd);
		if (node->tok == OUT)
			fd = open(node->file, rwx, mode);
		if (fd < 0)
			return (-1);
		node = node->rchild;
	}
	return (fd);
}
