/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:51:40 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/05 13:41:18 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"
#define IN 0
#define OUT 1

static	ssize_t	calc_ll(char *s)
{
	ssize_t	l;
	ssize_t	i;
	char	*var;

	l = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && is_identifier(s[i + 1]))
		{
			i++;
			var = expand_var(s, &i);
			l += ft_strlen(var);
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
	if (!ret)
		return (malloc_error(errno));
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
			return (-1);
		if (flg)
			input = expand_in_doc(input);
		if (write(fd[1], input, ft_strlen(input)) < 0)
			return (print_error(2, "write", strerror(errno)),
				exit_with_status(1), -1);
		(free(input), input = NULL);
	}
	if (close(fd[1]) < 0)
		return (-1);
	return (fd[0]);
}

static	void	handle_in_out(t_node *root)
{
	t_redir		*trav;

	trav = root->redirections;
	root->fd[IN] = ret_fd_in(trav);
	root->fd[OUT] = ret_fd_out(trav);
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
