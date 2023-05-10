/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:51:40 by fraqioui          #+#    #+#             */
/*   Updated: 2023/05/10 09:06:04 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishell.h"

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
			if (!var || !*var)
				continue ;
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
	char	*save;
	char	*var;
	ssize_t	i;

	ret = malloc(sizeof(char) * (calc_ll(s) + 1));
	if (!ret)
		return (malloc_error(errno));
	i = 0;
	save = ret;
	while (s[i])
	{
		if (s[i] == '$' && is_identifier(s[i + 1]))
		{
			i++;
			var = expand_var(s, &i);
			if (!var || !*var)
				continue ;
			while (*var)
				*ret++ = *var++;
		}
		else
			*ret++ = s[i++];
	}
	return (*ret = '\0', free(s), save);
}

static	int	handle_heredoc(char *delim, bool flg)
{
	int		fd[2];
	char	*input;
	char	*save;

	if (pipe_sc(fd) < 0)
		return (-1);
	while (1)
	{
		input = readline("> ");
		if (!input || !ft_memcmp(input, delim, ft_strlen(input) + 1))
		{
			free(input);
			break ;
		}
		if (flg)
			input = expand_in_doc(input);
		save = ft_strjoin(input, "\n");
		(free(input), input = save);
		if (_write_(fd[1], input, ft_strlen(input)) < 0)
			return (free(input), -1);
		(free(input), input = NULL);
	}
	return (close(fd[1]), fd[0]);
}

static	int	handle_in_out(t_node *root)
{
	if (ret_fd_in(root) < 0 || ret_fd_out(root) < 0)
		return (-1);
	return (0);
}

int	handle_redirections(t_node *root)
{
	t_redir	*trav;

	trav = root->redirections;
	while (trav)
	{
		if (trav->tok == HEREDOC)
		{
			trav->fd = handle_heredoc(trav->file, trav->flg);
			if (trav->fd < 0)
				return (-1);
		}
		trav = trav->rchild;
	}
	if (handle_in_out(root) < 0)
		return (-1);
	return (0);
}
