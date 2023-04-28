/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_defines.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:34:46 by fraqioui          #+#    #+#             */
/*   Updated: 2023/04/28 09:49:26 by fraqioui         ###   ########.fr       */
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

# define READ_END 0
# define WRITE_END 1
# define FATAL_SIGNAL 128
# define CMD_N_FOUND 127
# define NOT_EXEC 126
# define INCORRECT_USAGE 2

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
	char			*pre_cmd;
	char			**cmd;
	t_token			tok;
	int				precedence;
	t_redir			*redirections;
	struct s_node	*lchild;
	struct s_node	*rchild;
}t_node;

typedef struct s_env
{
	char			*env;
	char			*var;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_mem
{
	char			*s;
	char			**str;
	struct s_mem	*next;
}	t_mem;

typedef struct s_gb
{
	int		under_exec;
	int		exit_st;
	t_env	*env;
	t_mem	*mem;
}	t_gb;

extern	t_gb	gb;

#endif
