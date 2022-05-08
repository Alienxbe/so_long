# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 00:02:10 by mykman            #+#    #+#              #
#    Updated: 2022/05/08 02:37:45 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS
ifeq ($(OS),Windows_NT) 
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif

# Compilation
CC			=	@gcc
CFLAGS		=	-Wall -Wextra -Werror
ifeq (detected_OS, Linux)
	MLXFLAGS	:=	-lmlx_Linux -lXext -lX11 -lm -lz
else
	MLXFLAGS	:=	
endif

# Variables
NAME		=	so_long

# Files
INCLUDES	=	includes/
SRCS		=	main.c
OBJS		=	$(addprefix srcs/, ${SRCS:.c=.o})

# Rules
%.o:		%.c
	${CC} ${CFLAGS} -c -I./${INCLUDES} $< -o $@

$(NAME):	${OBJS}
	${CC} ${CFLAGS} $^ ${MLXFLAGS} -o $@

all:	$(NAME)

clean:
	@rm -f ${OBJS}

fclean:	clean
	@rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
