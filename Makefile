# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 14:02:45 by fraqioui          #+#    #+#              #
#    Updated: 2023/02/25 10:32:13 by fraqioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =minishell
CC = cc
FALGS = -Wall -Wextra -Werror
HEADER = headers/minishell.h 
RM = rm -rf 

FILES = parser/main \
		parser/tokenize \
		parser/tokenize_utils \
		minishell_utils/strlen \
		minishell_utils/split \
		minishell_utils/putstr \
		minishell_utils/strcmp \
		#tree_build/node_creation \
		#tree_build/tree_build \

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
