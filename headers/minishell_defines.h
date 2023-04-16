/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_defines.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:34:46 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/15 11:07:55 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINES_H
# define MINISHELL_DEFINES_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include"../utils/ft_printf/ft_printf.h"

typedef enum e_token
{
	PIPE,
	HEREDOC,
	LPR,
	RPR,
	AND,
	OR,
	APPEND,
	OUT,
	IN,
	NOT,
	END
}t_token;

typedef struct s_redir
{
	t_token			tok;
	char			*file;
	struct s_redir	*lchild;
	struct s_redir	*rchild;
}t_redir;

typedef struct s_node
{
	char			**cmd;
	t_token			tok;
	int				precedence;
	t_redir			*redirections;
	struct s_node	*lchild;
	struct s_node	*rchild;
}t_node;

#endif
