# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 14:02:45 by fraqioui          #+#    #+#              #
#    Updated: 2023/05/02 08:18:00 by fraqioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =minishell
CC = cc
FALGS = -Wall -Wextra -Werror
HEADER = headers/minishell.h
RM = rm -rf 
L = -L/Users/fraqioui/.brew/opt/readline/lib
I = -I/Users/fraqioui/.brew/opt/readline/include

FILES = parser/main \
		parser/initialize \
		parser/parser \
		parser/tokenize \
		parser/syntax \
		parser/re_order \
		parser/finalize \
		executor/executor/start \
		executor/executor/cmd \
		executor/executor/pipe \
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
		utils/libft/strdup \
		utils/libft/lstadd \
		utils/libft/get_env \
		utils/build/list_build \
		utils/build/node_creation \
		utils/build/tree_build \
		utils/ft_printf/hex \
		utils/ft_printf/number \
		utils/ft_printf/string \
		utils/ft_printf/start \
		utils/tokenize/tokenize_utils_1 \
		utils/tokenize/tokenize_utils_2 \
		utils/tokenize/tokenize_utils_3 \
		utils/executor/expanding_utils1 \
		utils/executor/expanding_utils2 \
		utils/executor/expanding_utils3 \
		utils/utils/checks \
		utils/utils/errors \
		utils/utils/evolve_func \
		utils/utils/lengths \
		utils/utils/memory \
		#executor/executor/and_or \
		executor/builtins/cd \
		executor/builtins/echo \
		executor/builtins/env \
		executor/builtins/exit \
		executor/builtins/export \
		executor/builtins/pwd \
		executor/builtins/unset \

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

re: all fclean

.PHONY = all clean fclean re
