# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 15:15:27 by franmart          #+#    #+#              #
#    Updated: 2023/01/06 14:31:02 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = src/
_SRC = 	parser.c\
		push_swap.c\
		sort.c\
		sort_small.c\
		stats.c\
		sorting_algorithm.c\
		utils.c\
		operations/swaps.c\
		operations/pushes.c\
		operations/rotates.c\
		operations/reverse_rotates.c\

SRC = ${addprefix ${SRC_DIR}, ${_SRC}}
OBJ = ${SRC:.c=.o}

LIBFT = lib/libft/libft.a
LIBFT_DIR = lib/libft

INCLUDES = -Iinc -L ${LIBFT_DIR} -lft

${NAME}: ${OBJ}
	$(MAKE) all bonus -C  $(LIBFT_DIR)
	$(CC) $(INCLUDES) $(OBJ) -o $(NAME) $(INCLUDES)
	@echo "$(NAME) compiled!"

%.o: %.c
	@${CC} ${FLAGS} -c $^ -o $@ -g3

all: ${NAME} ${LIBFT}

clean:
	@echo "Removing files..."
	@$(MAKE) clean -C  $(LIBFT_DIR)
	@${RM} ${OBJ} ${BONUS_OBJ}
	@echo "Done!"

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) fclean -C  $(LIBFT_DIR)

re:	fclean all

.PHONY:	all clean fclean re
