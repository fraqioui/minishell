/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_defines.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:34:46 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/24 11:01:49 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINES_H
# define MINISHELL_DEFINES_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_token
{
	PIPE,
	HEREDOC,
	AND,
	OR,
	APPEND,
	OUT,
	IN
}t_token;

typedef struct s_tree
{
	char			**str;
	t_token			tok;
	struct s_tree	*left;
	struct s_tree	*right;
}t_tree;

#endif
