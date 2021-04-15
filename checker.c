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

int	list_size(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	int		i;
	t_stack	*aux;

	if (!lst)
		return (NULL);
	i = 0;
	aux = lst;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	if (i == 0)
		return (lst);
	while (lst && i > 1)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack *aux;

	aux = ft_lstlast(*alst);
	if (new && alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			aux->next = new;
			new->next = NULL;
		}
	}
}

int		all_numbers_and_spaces(char *str)
{
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || *str == ' '))
			return (0);
		str++;
	}
	return (1);	
}

int		param_validator(char *str)
{
	if (!all_numbers_and_spaces(str))
		return (0);
	/**
	 * TODO: concat params.
	 * TODO: repeated_numbers.
	 * TODO: bigger than int.
	 */
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

void	sa_sb(t_stack **stack)
{
	t_stack	*tmp;

	if (list_size(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}

void	pa_pb(t_stack **to_be_taken, t_stack**to_be_added) {
	t_stack *tmp;

	if (*to_be_taken)
	{
		tmp = *to_be_taken;
		*to_be_taken = (*to_be_taken)->next;
		stack_add_to_front(to_be_added, tmp);
	}
}

void	ra_rb(t_stack **stack) {
	t_stack	*tmp;

	if (*stack) 
	{
		tmp = *stack;
		*stack = (*stack)->next;
		ft_lstadd_back(stack, tmp);
	}
}

void	checker(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	printf("a//\n");			////Just for testing, delete.
	print_list(a);				////Just for testing, delete.
	printf("b//\n");			////Just for testing, delete.
	print_list(b);				////Just for testing, delete.
	// sa_sb(&a);				////Just for testing, delete.
	// pa_pb(&a, &b);			////Just for testing, delete.
	// ra_rb(&a);				////Just for testing, delete.
	printf("a///////\n");		////Just for testing, delete.
	print_list(a);				////Just for testing, delete.
	printf("b///////\n");		////Just for testing, delete.
	print_list(b);				////Just for testing, delete.
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	checker(stack_init(argc - 1, ++argv));
}

