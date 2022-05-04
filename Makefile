# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 10:06:54 by lsuau             #+#    #+#              #
#    Updated: 2021/12/15 15:33:50 by lsuau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEX = push_swap
BONUS = checker

INC = push_swap.h get_next_line.h

SRC = push_swap_main.c init.c parsing.c error.c stock_lst.c stock.c petit_tri.c moyen_tri.c operation.c operation2.c operation3.c
SRC_BONUS = checker_main.c init.c parsing.c moyen_tri.c error.c stock_lst.c stock.c operation_s.c operation_s2.c operation.c operation2.c operation3.c get_next_line.c get_next_line_utils.c

GCC = gcc -Wall -Werror -Wextra

OBJ_DIR = obj/
OBJ = ${addprefix ${OBJ_DIR}, ${SRC:.c=.o}}
OBJ_BONUS = ${addprefix ${OBJ_DIR}, ${SRC_BONUS:.c=.o}}

all : ${NAMEX}

${OBJ_DIR}%.o : %.c ${INC} Makefile
	${GCC} -c $< -o $@

${NAMEX}: ${OBJ} ${INC}
	${GCC} ${OBJ} -o ${NAMEX}

${BONUS}: ${OBJ_BONUS} ${INC}
	${GCC} ${OBJ_BONUS} -o ${BONUS}

${OBJ}: | ${OBJ_DIR}
${OBJ_BONUS}: | ${OBJ_DIR}

${OBJ_DIR}:
	mkdir ${OBJ_DIR}

clean :
	rm -rf ${OBJ_DIR}

fclean : clean
	rm -f ${NAMEX}
	rm -f ${BONUS}

re : fclean all

.PHONY: bonus all clean fclean re
