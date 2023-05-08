# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaillea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 16:08:29 by acaillea          #+#    #+#              #
#    Updated: 2022/01/26 16:08:31 by acaillea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ./Includes/colors.mk

#--------------------------------------------------------------------#

NAME	=	push_swap

NAME_C	=	checker

#--------------------------------------------------------------------#

SRC_DIR	= 	./Sources/

SRC_C_DIR = ./Sources_bonus/

SRC_M	= 	main.c

SRC		= 	utils.c 		\
			init.c			\
			little_sort.c	\
			moves.c			\
			moves_2.c 		\
			moves_utils.c	\
			big_sort.c


SRC_C	=	checker_bonus.c			\
			get_next_line_bonus.c	\
			utils_bonus.c			\


#--------------------------------------------------------------------#

INC		= ./Includes/push_swap.h

#--------------------------------------------------------------------#

OBJ_DIR	= ./Objects/

OBJS	= $(addprefix ${OBJ_DIR}, ${SRC:%.c=%.o})
OBJS_M	= $(addprefix ${OBJ_DIR}, ${SRC_M:%.c=%.o})
OBJS_C	= $(addprefix ${OBJ_DIR}, ${SRC_C:%.c=%.o})

#--------------------------------------------------------------------#

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
MK		= mkdir -p
RM		= /bin/rm -f
VEL		= sleep
PRI		= printf

#--------------------------------------------------------------------#

all: ${NAME}

bonus: ${NAME_C}

#--------------------------------------------------------------------#

${OBJ_DIR}:
	@${MK} ${OBJ_DIR}

${OBJ_DIR}%.o:${SRC_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@ -I ${INC}
	@${PRI} "${C_MAG}	Compiling push_swap :	\
	${C_CYAN}[${C_ORANGE}$<${C_CYAN}] $(C_RESET) $(L_CLEAR)\r${C_DEFAUT}"
	@${VEL} 0.5
	@printf "$(L_CLEAR)\r"

${OBJ_DIR}%.o:${SRC_C_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@ -I ${INC}
	@${PRI} "${C_MAG}	Compiling checker :	\
	${C_CYAN}[${C_ORANGE}$<${C_CYAN}] $(C_RESET) $(L_CLEAR)\r${C_DEFAUT}"
	@${VEL} 0.5
	@printf "$(L_CLEAR)\r"

${NAME}: ${OBJ_DIR} ${OBJS} ${OBJS_M}
	@${CC} ${CFLAGS} ${OBJS} ${OBJS_M} -o ${NAME}
	@${PRI} "\n${C_CYAN}[${C_GREEN}✔︎${C_CYAN}]	\
	${C_MAG}$@ . . . ${C_GREEN}Successfully build\n\n${C_DEFAUT}"

${NAME_C}: ${OBJ_DIR} ${OBJS} ${OBJS_C}
	@${CC} ${CFLAGS} ${OBJS} ${OBJS_C} -o ${NAME_C}
	@${PRI} "\n${C_CYAN}[${C_GREEN}✔︎${C_CYAN}]	\
	${C_MAG}$@ . . . . ${C_GREEN}Successfully build\n\n${C_DEFAUT}"

#--------------------------------------------------------------------#

clean:
	@${RM} -r ${OBJ_DIR}
	@${PRI} "\n${C_CYAN}[${C_GREEN}✔︎${C_CYAN}]	${C_RED}Files Deleted \
	\n\n${C_DEFAUT}"

fclean: clean
	@${RM} ${NAME} ${NAME_C}
	@${PRI} "${C_CYAN}[${C_GREEN}✔︎${C_CYAN}]	${C_RED}Exe's Deleted \
	\n\n${C_DEFAUT}"

re: fclean all

.PHONY: all clean fclean re bonus
