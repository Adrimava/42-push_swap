/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:11 by marvin            #+#    #+#             */
/*   Updated: 2021/04/12 17:59:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*new_stack(int content)
{
	t_stack	*new_stack;

	if (!(new_stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new_stack->number = content;
	new_stack->next = NULL;
	return (new_stack);
}

void	stack_add_to_front(t_stack **alst, t_stack *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
	return ;
}

void	print_list(t_stack *lst)
{
	while (lst)
	{
		printf("%d\n", lst->number);
		lst = lst->next;
	}
}

int		all_numbers_and_spaces(char *str)
{
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || *str == ' '))
			return (0);
		*str++;
	}
	return (1);	
}

int		param_validator(char *str)
{
	if (!all_numbers_and_spaces(str))
		return (0);
	return (1);
}

t_stack	*stack_init(int size,  char **params)
{
	t_stack	*first_number;
	int		i;

	first_number = NULL;
	i = size;
	while (--i >= 0)
	{
		if (!param_validator(params[i]))
		{
			printf("Error\n");
			return (NULL);
		}
		else
			stack_add_to_front(&first_number, new_stack(atoi(params[i])));
	}
	return (first_number);
}

int		main(int argc, char **argv)
{
	t_stack *a;

	if (argc == 1)
		return (0);
	a = stack_init(argc - 1, ++argv);
	print_list(a);
}

