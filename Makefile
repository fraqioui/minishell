# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 14:02:45 by fraqioui          #+#    #+#              #
#    Updated: 2023/04/17 11:11:30 by fraqioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =minishell
CC = cc
FALGS = -Wall -Wextra -Werror
HEADER = headers/minishell.h
RM = rm -rf 

FILES = parser/main \
		parser/parser \
		parser/tokenize \
		parser/syntax \
		parser/re_order \
		executor/executor/start \
		executor/executor/and_or \
		executor/executor/cmd \
		executor/executor/pipe \
		executor/builtins/cd \
		executor/builtins/echo \
		executor/builtins/env \
		executor/builtins/exit \
		executor/builtins/export \
		executor/builtins/pwd \
		executor/builtins/unset \
		executor/expander/expanding \
		utils/libft/strtrim \
		utils/libft/putstr \
		utils/libft/strlen \
		utils/libft/calloc \
		utils/libft/split \
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
		#minishell_utils/strcmp \

FOBJ = ${FILES:=.o}

all: ${NAME}

${NAME}: ${FOBJ} ${HEADER}
	${CC} ${FALGS} -lreadline ${FOBJ} -o $@

%.o: %.c
	${CC} ${FALGS} -c $< -o $@

clean:
	${RM} ${FOBJ}

fclean: clean
	${RM} ${NAME}

re: all fclean

.PHONY = all clean fclean re
