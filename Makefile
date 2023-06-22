# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 17:12:33 by hasabir           #+#    #+#              #
#    Updated: 2022/07/03 20:57:56 by hasabir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = main.c check_errors.c pipex_utils.c split.c pipex_utils_2.c pipex_utils_3.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : ${NAME}

%.o : %.c
	@${CC} -c ${CFLAGS} $< 

${NAME} :${OBJS}
	@$(CC) $(OBJS) -o $(NAME)


clean:
	@rm -rf ${OBJS}

fclean: clean
	@rm -rf ${NAME}

re: fclean all