# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 00:02:10 by mykman            #+#    #+#              #
#    Updated: 2022/05/28 13:59:12 by mykman           ###   ########.fr        #
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
NAME_BUILDER	=	builder
LIBFT_FOLDER	=	Libft/
LIBFT_NAME		=	libft.a
MAKE_LIBFT		=	@make -s -C ${LIBFT_FOLDER}
MLX_FOLDER		=	minilibx_${detected_OS}
MLX_NAME		=	libmlx.a
MAKE_MLX		=	@make -s -C ${MLX_FOLDER}

# Files
INCLUDES		=	-I./includes -I./${LIBFT_FOLDER}/includes -I./${MLX_FOLDER}
SRCS			=	assets.c \
					errors.c \
					events.c \
					ft_area.c \
					ft_mlx.c \
					ft_point.c \
					map.c \
					parsing.c \
					render.c \
					window.c
SRCS_SOLONG		=	$(addsuffix .c, ${NAME}) \
					draw.c \
					key.c
SRCS_BUILDER	=	$(addsuffix .c, ${NAME_BUILDER}) \
					draw.c \
					key.c \
					map.c

OBJS			=	$(addprefix srcs/common/, ${SRCS:.c=.o})
OBJS_SOLONG		=	$(addprefix srcs/solong/, ${SRCS_SOLONG:.c=.o})
OBJS_BUILDER	=	$(addprefix srcs/builder/, ${SRCS_BUILDER:.c=.o})

# Rules
%.o:		%.c
	${CC} ${CFLAGS} -D OS=\"${detected_OS}\" -c ${INCLUDES} $< -o $@

$(NAME):	${OBJS} ${OBJS_SOLONG}
	${MAKE_LIBFT}
	${MAKE_MLX}
	${CC} ${CFLAGS} ${INCLUDES} $^ ${LIBFT_FOLDER}/${LIBFT_NAME} ${MLX_FOLDER}/${MLX_NAME} ${MLXFLAGS} -o $@

$(NAME_BUILDER):	${OBJS} ${OBJS_BUILDER}
	${MAKE_LIBFT}
	${MAKE_MLX}
	${CC} ${CFLAGS} ${INCLUDES} $^ ${LIBFT_FOLDER}/${LIBFT_NAME} ${MLX_FOLDER}/${MLX_NAME} ${MLXFLAGS} -o $@


all:	$(NAME)

clean:
	${MAKE_MLX} clean
	${MAKE_LIBFT} clean
	@rm -f ${OBJS} ${OBJS_BUILDER} ${MAIN} ${MAIN_BUILDER}

fclean:
	${MAKE_MLX} clean
	${MAKE_LIBFT} fclean
	@rm -f ${NAME} ${NAME_BUILDER} ${OBJS} ${OBJS_BUILDER} ${MAIN} ${MAIN_BUILDER}

re:		fclean all

.PHONY:	all clean fclean re
