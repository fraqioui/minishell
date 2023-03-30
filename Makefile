# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 14:02:45 by fraqioui          #+#    #+#              #
#    Updated: 2023/03/29 09:11:43 by fraqioui         ###   ########.fr        #
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
		parser/tokenize_utils \
		utils/libft/strtrim \
		utils/libft/putstr \
		utils/libft/strlen \
		utils/libft/calloc \
		utils/libft/split \
		utils/build/list_build \
		utils/build/node_creation \
		utils/ft_printf/hex \
		utils/ft_printf/number \
		utils/ft_printf/string \
		utils/ft_printf/start \
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
