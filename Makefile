# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 16:06:21 by fborroto          #+#    #+#              #
#    Updated: 2023/08/13 19:19:28 by fborroto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c

OBJ = *.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all :
	@${CC} $(FLAGS) server.c -o server
	@${RM} $(OBJ)
	@${CC} $(FLAGS) client.c -o client
	@${RM} $(OBJ)

clean: 
	@${RM} ${OBJ}

fclean: clean
	@${RM} server
	@${RM} client

re: fclean all
