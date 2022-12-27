# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 15:15:27 by franmart          #+#    #+#              #
#    Updated: 2022/12/10 17:18:26 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = # program name

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -rf

SRC_DIR = src/
_SRC = # files
SRC = ${addprefix ${SRC_DIR}, ${_SRC}}
OBJ = ${SRC:.c=.o}

_BONUS = # bonus files
BONUS = ${addprefix ${SRC_DIR}, ${_BONUS}}

BONUS_OBJ = ${BONUS:.c=.o}

${NAME}: ${OBJ}
	@${LIB} $@ $^
	@echo "$(NAME) compiled!"

%.o: %.c
	@${CC} ${FLAGS} -c $^ -o $@

all:
	@${NAME}

clean:
	@echo "Removing files..."
	@${RM} ${OBJ} ${BONUS_OBJ}
	@echo "Done!"

fclean: clean
	@${RM} ${NAME}

re:	fclean all

bonus: ${OBJ} ${BONUS_OBJ}
	@${LIB} ${NAME} ${OBJ} ${BONUS_OBJ}
	@echo "$(NAME) bonus compiled!"

.PHONY:	all clean fclean re bonus
