# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 17:11:25 by arakiztain        #+#    #+#              #
#    Updated: 2025/11/13 17:11:28 by arakiztain       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


SRC = push_swap.c \
      ft_atoi.c \
      swap.c \
      push.c \
      rotate.c \
      rrotate.c \
      handle_error.c \
      aux.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette $(SRC) push_swap.h

run:
	./$(NAME)

check:
	ARG="4 67 3 87 23"; ./$(NAME) $$ARG | ./checker_linux $$ARG

.PHONY: all clean fclean re norm run check
