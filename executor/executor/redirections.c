/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:51:40 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/03 10:21:52 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"
#define IN 0
#define OUT 1
#define APPEND 2

static	ssize_t	calc_ll(char *s)
{
	ssize_t	l;
	ssize_t	i;

	l = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && is_identifier(s[i + 1]))
		{
			i++;
			l += ft_strlen(expand_var(s, &i));
		}
		else
		{
			i++;
			l++;
		}
	}
	return (l);
}

static	char	*expand_in_doc(char *s)
{
	char	*ret;
	char	*var;
	ssize_t	i;

	ret = malloc(sizeof(char) * (calc_ll(s) + 1));
	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && is_identifier(s[i + 1]))
		{
			i++;
			var = expand_var(s, &i);
			*ret++ = *var++;
		}
		else
			*ret++ = s[i++];
	}
	*ret = '\0';
	return (ret);
}

static	int	handle_heredoc(char *delim, bool flg)
{
	int		fd[2];
	char	*input;

	if (pipe_sc(fd) < 0)
		return (-1);
	while (1)
	{
		if (!ft_memcmp(input, delim, ft_strlen(input) + 1))
			break ;
		input = readline("> ");
		if (!input)
			return (-1);//close
		if (flg)
			input = expand_in_doc(input);
		if (write(fd[1], input, ft_strlen(input)) < 0)
			return (print_error("write", strerror(errno), 1, 1), -1);
		free(input);
	}
	if (_close_("a", fd[1]) < 0)
		return (-1);
	return (fd[0]);
}

static	void	handle_in_out(t_node *root)
{
	t_redir		*trav;
	int			fd[2];
	mode_t		mode;
	int			rwx[3];

	mode = 00644;
	rwx[OUT] = (O_CREAT | O_WRONLY | O_TRUNC);
	rwx[APPEND] = (O_CREAT | O_WRONLY | O_APPEND);
	trav = root->redirections;
	while (trav)
	{
		if (trav->tok == IN)
			fd[IN] = _open_(trav->file, O_RDONLY, mode);
		else if (trav->tok == OUT)
			fd[OUT] = _open_(trav->file, rwx[OUT], mode);
		else if (fd[IN] > 0 && trav->tok == APPEND)
			fd[IN] = _open_(trav->file, rwx[APPEND], mode);
		else if (fd[IN] > 0 && trav->tok == HEREDOC)
			fd[IN] = trav->fd;
		if (fd[IN] < 0 || fd[OUT] < 0)
			return ;
		trav = trav->rchild;
	}
	root->fd[IN] = fd[IN];
	root->fd[OUT] = fd[OUT];
}

void	handle_redirections(t_node *root)
{
	t_redir	*trav;

	trav = root->redirections;
	while (trav)
	{
		if (trav->tok == HEREDOC)
		{
			trav->fd = handle_heredoc(trav->file, trav->flg);
			if (trav->fd < 0)
				return ;
		}
		trav = trav->lchild;
	}
	handle_in_out(root);
}
