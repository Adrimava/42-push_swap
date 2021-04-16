# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/16 19:13:53 by amaza-va          #+#    #+#              #
#    Updated: 2021/04/16 20:50:48 by amaza-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSHSWAP = pushswap

HEADER  = push_swap.h

CHECKER_SRCS = checker.c
PUSHSWAP_SRCS = push_swap.c

LIB_LIST = liblist/ft_lstadd_back.c liblist/ft_lstadd_front.c liblist/ft_lstclear.c liblist/ft_lstdelone.c \
			liblist/ft_lstiter.c liblist/ft_lstlast.c liblist/ft_lstmap.c liblist/ft_lstnew.c liblist/ft_lstsize.c
LIBFT = libft/libft.a
GNL = gnl/get_next_line.c

SRCS =	array_utils.c			\
		checker_init.c			\
		checker_instructions.c	\
		checker_stack_list.c	\
		checker_stack_list2.c	\
		checker_validator.c		\
		checker_input.c

FLAGS = -Wall -Wextra -Werror 

SANITIZE= -fsanitize=address

GCC = gcc

all:
	@Make re -C ./libft
	@$(GCC) $(CHECKER_SRCS) $(SRCS) $(LIB_LIST) $(GNL) $(LIBFT) -o checker

checker: 
	$(GCC) $(CHECKER_SRCS) $(SRCS) $(LIB_LIST) $(GNL) $(LIBFT) -o $@
#$(FLAGS)

pushswap:
	$(GCC) $(FLAGS) $(PUSHSWAP_SRCS) $(SRCS) $(GNL) $(LIB_LIST) $(LIBFT) -o $@

clean:
	rm -f $(CHECKER)

fclean:   clean
	rm -rf $(CHECKER) $(PUSHSWAP)

re:     fclean all