# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/16 19:13:53 by amaza-va          #+#    #+#              #
#    Updated: 2021/04/19 20:19:53 by amaza-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSHSWAP = pushswap

HEADER  = checker.h

CHECKER_SRCS = checker.c
PUSHSWAP_SRCS = push_swap.c

LIBFT = libft/libft.a
GNL = gnl/get_next_line.c

SRCS =	array_utils.c			\
		ft_strcmp.c				\
		ft_atol.c				\
		checker_init.c			\
		checker_instructions.c	\
		checker_stack_list.c	\
		checker_stack_list2.c	\
		checker_validator.c		\
		checker_input.c			\
		checker_result.c		\
		push_swap_sorting.c

FLAGS = -Wall -Wextra -Werror 

SANITIZE= -fsanitize=address

GCC = gcc

all: checker push_swap

checker: lib
	@$(GCC) $(FLAGS) $(CHECKER_SRCS) $(SRCS) $(GNL) $(LIBFT) -o $@

push_swap: lib
	@$(GCC) $(FLAGS) $(PUSHSWAP_SRCS) $(SRCS) $(GNL) $(LIBFT) -o $@

lib:
	@make re -C ./libft

clean:
	@rm -f $(CHECKER)

fclean:   clean
	@rm -rf $(CHECKER) $(PUSHSWAP)

re:     fclean all