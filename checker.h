/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:17:36 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/16 14:58:01 by amaza-va         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int     ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);

#endif