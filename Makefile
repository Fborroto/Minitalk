# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 16:06:21 by fborroto          #+#    #+#              #
#    Updated: 2023/11/06 12:32:30 by fborroto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C	=	client
NAME_S	=	server

SRCS_C	=	client.c ft_atoi.c
SRCS_S	=	server.c ft_atoi.c

OBJS_C	=	${SRCS_C:.c=.o}
OBJS_S	=	${SRCS_S:.c=.o}

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
PRINTF	=	./ft_printf
LIPRIN	=	ft_printf/libftprintf.a

all:
		make -C $(PRINTF)
		${CC} ${FLAGS} ${SRCS_C} ${LIPRIN} -o ${NAME_C}
		${CC} ${FLAGS} ${SRCS_S} ${LIPRIN} -o ${NAME_S}

client:
		make -C $(PRINTF)
		${CC} ${FLAGS} ${SRCS_C} ${LIPRIN} -o ${NAME_C}
		
server:
		make -C $(PRINTF)
		${CC} ${FLAGS} ${SRCS_S} ${LIPRIN} -o ${NAME_S}

clean:
		make clean -C ${PRINTF}
		${RM} ${OBJS_C}
		${RM} ${OBJS_S}

fclean:	clean
		make fclean -C ${PRINTF}
		${RM} ${NAME_C}
		${RM} ${NAME_S}
		
re:		fclean all

.PHONY:	all clean fclean re