# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garakizt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 13:03:14 by garakizt          #+#    #+#              #
#    Updated: 2025/07/26 13:03:25 by garakizt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRC = ft_split.c ft_substr.c ft_putstr.c ft_atoi.c ft_isdigit.c \
	ft_strlen.c ft_putchar.c ft_calloc.c ft_strchr.c ft_strdup.c \
	ft_strtrim.c ft_memset.c ft_putstr_fd.c

OBJ = $(SRC:%.c=%.o)

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re