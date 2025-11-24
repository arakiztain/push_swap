# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 17:11:25 by arakiztain        #+#    #+#              #
#    Updated: 2025/11/24 10:55:01 by arakiztain       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a
INC = incs
SRC_DIR = srcs/
SRC_FILES = checks.c push_swap.c free.c main.c utils.c \
	movements.c sort1.c sort2.c position.c doublemoves.c \
	movements2.c mainmoves.c utils1.c 
	
HEADER = incs/push_swap.h 

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -I $(INC) -o $(NAME) $(OBJ) -Llibft -lft

$(LIBFT):
	$(MAKE) -C libft

%.o: src/%.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
