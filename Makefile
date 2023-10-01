# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 15:15:27 by franmart          #+#    #+#              #
#    Updated: 2023/10/01 18:50:53 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

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
		operations/reverse_rotates.c

SRC = ${addprefix ${SRC_DIR}, ${_SRC}}
OBJ = ${SRC:.c=.o}

BONUS_DIR = src/
_BONUS = checker/checker.c\
		checker/instructions.c\
		parser.c\
		sort.c\
		sort_small.c\
		stats.c\
		sorting_algorithm.c\
		utils.c\
		operations/swaps.c\
		operations/pushes.c\
		operations/rotates.c\
		operations/reverse_rotates.c
BONUS = ${addprefix ${BONUS_DIR}, ${_BONUS}}
BONUS_OBJ = ${BONUS:.c=.o}

LIBFT = lib/libft/libft.a
LIBFT_DIR = lib/libft

INCLUDES = -I ./inc -I ${LIBFT_DIR}/include

${NAME}: ${OBJ}
	@echo "Compiling $(NAME)..."
	@echo "Compiling dependencies..."
	@$(MAKE) -s all bonus -C $(LIBFT_DIR)
	@$(CC) $(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(NAME) compiled!"

${BONUS_NAME}: ${BONUS_OBJ}
	@echo "Compiling $(BONUS_NAME)..."
	@echo "Compiling dependencies..."
	@$(MAKE) -s all bonus -C $(LIBFT_DIR)
	@$(CC) $(INCLUDES) $(BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)
	@echo "$(BONUS_NAME) compiled!"

%.o: %.c
	@git submodule update --init --recursive
	@${CC} ${FLAGS} $(INCLUDES) -c $^ -o $@

bonus: $(BONUS_NAME) ${LIBFT}

all: ${NAME} ${LIBFT}

clean:
	@echo "Removing files..."
	@echo "Removing dependencies..."
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@${RM} ${OBJ} ${BONUS_OBJ}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${BONUS_NAME}
	@$(MAKE) -s fclean -C  $(LIBFT_DIR)

re:	fclean all

test: ${NAME} bonus
	python3 tester.py -n 3
	python3 tester.py -n 5
	python3 tester.py -n 100
	python3 tester.py -n 500

.PHONY:	all clean fclean re bonus test
