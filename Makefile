# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 23:42:15 by fraqioui          #+#    #+#              #
#    Updated: 2023/05/10 00:16:07 by fraqioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
FALGS = -Wall -Wextra -Werror
HEADER = headers/minishell.h
RM = rm -rf 
L = -L/Users/fraqioui/.brew/opt/readline/lib
I = -I/Users/fraqioui/.brew/opt/readline/include

FILES = parser/main \
		parser/initialize \
		parser/initialize_hlp \
		parser/parser \
		parser/tokenize \
		parser/syntax \
		parser/re_order \
		parser/signals \
		executor/builtins/exit \
		executor/builtins/cd \
		executor/builtins/cd_hlp \
		executor/builtins/echo \
		executor/builtins/env \
		executor/builtins/export \
		executor/builtins/export_help \
		executor/builtins/pwd \
		executor/builtins/unset \
		executor/executor/start \
		executor/executor/cmd \
		executor/executor/cmd_helper \
		executor/executor/pipe \
		executor/executor/and_or \
		executor/executor/redirections \
		executor/executor/redir_hlp \
		executor/expander/expanding \
		executor/expander/wildcard \
		executor/expander/wildcard_utils \
		utils/libft/strtrim \
		utils/libft/putstr \
		utils/libft/strlen \
		utils/libft/calloc \
		utils/libft/split \
		utils/libft/substr \
		utils/libft/memcmp \
		utils/libft/strcmp \
		utils/libft/strdup \
		utils/libft/lstadd \
		utils/libft/get_env \
		utils/libft/atoi \
		utils/libft/itoa \
		utils/libft/strjoin \
		utils/build/list_build \
		utils/build/node_creation \
		utils/build/tree_build \
		utils/ft_printf/hex \
		utils/ft_printf/number \
		utils/ft_printf/string \
		utils/ft_printf/start \
		utils/tokenize/tokenize_utils_1 \
		utils/tokenize/tokenize_utils_2 \
		utils/executor/expanding_utils1 \
		utils/executor/expanding_utils2 \
		utils/executor/expanding_utils3 \
		utils/utils/checks \
		utils/utils/checks_ \
		utils/utils/errors \
		utils/utils/evolve_func \
		utils/utils/evolve_func_ \
		utils/utils/lengths \
		utils/utils/memory \

FOBJ = ${FILES:=.o}

all: ${NAME}

${NAME}: ${FOBJ} ${HEADER}
	${CC} ${FALGS} ${FOBJ} -o $@ -lreadline ${L}

%.o: %.c
	${CC} ${FALGS} -c $< -o $@ ${I}

clean:
	${RM} ${FOBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY = all clean fclean re
