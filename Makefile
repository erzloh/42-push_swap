# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 21:33:09 by eric              #+#    #+#              #
#    Updated: 2023/01/19 16:07:20 by eholzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRCS_LIST		=	main.c \
					utils.c \
					instructions_1.c \
					instructions_2.c \
					instructions_3.c \
					check_int_max.c \
					check_errors.c
SRCS_DIR		=	sources/
SRCS			=	${addprefix ${SRCS_DIR}, ${SRCS_LIST}}

OBJS_LIST		=	${SRCS_LIST:.c=.o}
OBJS_DIR		=	objects/
OBJS			=	${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

LIB				=	libft.a
LIB_DIR			=	libft

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g

all:			${NAME}

${OBJS_DIR}:
				mkdir ${OBJS_DIR}

${OBJS_DIR}%.o:	${SRCS_DIR}%.c
				${CC} ${CFLAGS} -c $^ -o $@

${NAME}:		${OBJS_DIR} ${OBJS}
				make -C ${LIB_DIR}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB_DIR}/${LIB}

clean:
				rm -rf ${OBJS_DIR}
				make -C ${LIB_DIR} clean

fclean:			clean
				rm -f ${NAME}
				rm -f ${LIB_DIR}/${LIB}

re:				fclean all

.PHONY:			all clean fclean re