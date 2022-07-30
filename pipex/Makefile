# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 20:55:35 by florianma         #+#    #+#              #
#    Updated: 2021/09/15 11:22:13 by florianma        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_split.c \
	   srcs/ft_strjoin.c \
	   srcs/main.c \
	   srcs/utils.c \
	   srcs/parent_child_load.c \
	   srcs/error_gestion.c \
	   srcs/free_str_split.c \
	   srcs/parsing.c \

OBJS = ${SRCS:.c=.o}

HEADER	= includes

NAME = pipex

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADER) -o $(NAME) $(OBJS)
	@echo "\033[33;32m=== Compilation pipex \t\t\tOK! √\n"

%.o : %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
