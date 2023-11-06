# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 01:04:11 by fborroto          #+#    #+#              #
#    Updated: 2023/03/03 01:04:11 by fborroto         ###   ########.fr        #
#                                                                              #
# ****************************************************************************

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putstring.c ft_putnbr.c ft_unsigned.c \
		ft_hexa.c ft_bighexa.c ft_vpointer.c \

		

OBJS = ${SRCS:.c=.o}

CC	= gcc
RM	= rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
