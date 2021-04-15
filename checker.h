/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:17:36 by marvin            #+#    #+#             */
/*   Updated: 2021/04/12 18:17:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_stack
{
    int				number;
    struct s_stack	*next;
}					t_stack;

t_stack	*new_stack(int content);
void	stack_add_to_front(t_stack **alst, t_stack *new);
void	print_list(t_stack *lst);
int		list_size(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
int		all_numbers_and_spaces(char *str);
int		param_validator(char *str);
t_stack	*stack_init(int size,  char **params);
void	sa_sb(t_stack **stack);
void	pa_pb(t_stack **to_be_taken, t_stack**to_be_added);
void	ra_rb(t_stack **stack);
void	rra_rrb(t_stack **stack);
void	checker(t_stack *a);

#endif