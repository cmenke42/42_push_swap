# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 21:07:24 by cmenke            #+#    #+#              #
#    Updated: 2023/05/02 20:50:29 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# := sets the value only once

NAME := push_swap

SRCDIR := mandatory

OPERATIONDIR := $(addprefix operations/,push.c \
							reverse_rotate.c \
							rotate.c \
							swap.c)

SRCS := $(addprefix ${SRCDIR}/,main.c \
							create_and_modify_nodes.c \
							get_info_about_list.c \
							read_check_input.c \
							sort_stack_a.c \
							assign_future_index.c \
							rotate_stacks.c \
							operation_counter.c \
							push_all_nums_to_stack_b.c \
							${OPERATIONDIR})


OBJS := ${SRCS:.c=.o}

HEADER := ${SRCDIR}/push_swap.h

LIBFTDIR := libft

LIBFT := libft.a

INCLUDE := ${LIBFTDIR}/${LIBFT}

CFLAGS := -Wall -Werror -Wextra

CC := cc

RM := rm -f

all: library ${NAME}

library:
	make -C ${LIBFTDIR}

${NAME}: ${OBJS} ${LIBFTDIR}/${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${INCLUDE} -o ${NAME}

${OBJS}: ${HEADER}

clean:
	${RM} ${OBJS}
	make clean -C ${LIBFTDIR}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFTDIR}

re: fclean all

.PHONY: all clean fclean re library

.NOTPARALLEL: