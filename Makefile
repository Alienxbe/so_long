# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maykman <maykman@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 00:02:10 by mykman            #+#    #+#              #
#    Updated: 2022/05/13 18:44:50 by maykman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS
ifeq ($(OS),Windows_NT) 
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif

# Compilation
CC				=	@gcc
CFLAGS			=	-Wall -Wextra -Werror
ifeq ($(detected_OS), Linux)
	MLXFLAGS	:=	-lXext -lX11 -lm -lz
else ifeq ($(detected_OS), Darwin)
	MLXFLAGS	:=	-framework OpenGL -framework AppKit
endif

# Variables
NAME			=	so_long
LIBFT_FOLDER	=	Libft/
LIBFT_NAME		=	libft.a
MAKE_LIBFT		=	@make -s -C ${LIBFT_FOLDER}
MLX_FOLDER		=	minilibx_${detected_OS}
MLX_NAME		=	libmlx.a
MAKE_MLX		=	@make -s -C ${MLX_FOLDER}

# Files
INCLUDES		=	-I./includes -I./${LIBFT_FOLDER}/includes -I./${MLX_FOLDER}
SRCS			=	main.c
OBJS			=	$(addprefix srcs/, ${SRCS:.c=.o})

# Rules
%.o:		%.c
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@

$(NAME):	${OBJS}
	${MAKE_LIBFT}
	${MAKE_MLX}
	${CC} ${CFLAGS} $^ ${LIBFT_FOLDER}/${LIBFT_NAME} ${MLX_FOLDER}/${MLX_NAME} ${MLXFLAGS} -o $@

all:	$(NAME)

clean:
	${MAKE_MLX} clean
	${MAKE_LIBFT} clean
	@rm -f ${OBJS}

fclean:
	${MAKE_MLX} clean
	${MAKE_LIBFT} fclean
	@rm -f ${NAME} ${OBJS}

re:		fclean all

.PHONY:	all clean fclean re
