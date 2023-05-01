# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 21:07:24 by cmenke            #+#    #+#              #
#    Updated: 2023/05/01 21:13:40 by cmenke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# := sets the value only once

NAME := push_swap

SRCDIR := mandatory

SRCS := $(addprefix ${SRCDIR}/,main.c \
							create_nodes_1.c \
							create_nodes_2.c \
							helper_functions.c \
							push.c \
							reverse_rotate.c \
							rotate.c \
							swap.c \
							read_check_input.c \
							sort_stack_a.c \
							assign_future_index.c \
							rotate_stacks.c \
							operation_counter.c)

# BSCRDIR := bonus

# BSRCS := $(addprefix ${BSCRDIR}/,main_bonus.c)

OBJS := ${SRCS:.c=.o}

# BOBJS := ${BSRCS:.c=.o}

HEADER := ${SRCDIR}/push_swap.h

# BHEADER := ${BSCRDIR}/push_swap_bonus.h

LIBFTDIR := libft

LIBFT := libft.a

INCLUDE := ${LIBFTDIR}/${LIBFT}

CFLAGS := -Wall -Wextra
# CFLAGS := -Wall -Werror -Wextra

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
# ${RM} ${BOBJS}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFTDIR}

# bonus: library ${BOBJS} ${LIBFTDIR}/${LIBFT}
# 	${CC} ${CFLAGS} ${BOBJS} ${INCLUDE} -o ${NAME}

# ${BOBJS}: ${BHEADER}

re: fclean all

.PHONY: all clean fclean re library
# .PHONY: all clean fclean re library bonus

.NOTPARALLEL: