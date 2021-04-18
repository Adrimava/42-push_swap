/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:31:35 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/18 21:35:04 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_list(t_stack **stack)
{
	t_stack	*tmp;

	while (list_size(*stack) > 0)
	{
		tmp = *stack;
		*stack = tmp->next;
		free(tmp);
	}
}

char	*ok_ko(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;
	
	if (list_size(*b))
		return ("KO");
	tmp = *a;
	i = 0;
	while (i < list_size(*a) - 1)
	{
		if (tmp->number > tmp->next->number)
			return ("KO");
		tmp = tmp->next;
		i++;
	}
	return ("OK");	
}

int		graphic_print(t_stack **stack)
{
	int		i;
	int		max;
	int		min;
	t_stack	*tmp;

	if (!(*stack))
		return (0);
	tmp = *stack;
	max = (*stack)->number;
	min = (*stack)->number;
	i = 0;
	while (i < list_size(tmp))
	{
		if (max < tmp->number)
			max = tmp->number;
		if (min > tmp->number)
			min = tmp->number;
		tmp = tmp->next;
	}
	return (min >= 0 && max <= 100);
}

void	stack_print(t_stack **stack)
{
	int		i;
	int		j;
	t_stack	*tmp;

	tmp = *stack;
	i = 0;
	while (i < list_size(tmp))
	{
		j = 0;
		while (j++ < (tmp)->number)
			printf("▣");
		printf("\n");
		tmp = tmp->next;	
	}
}

void	result(t_stack **a, t_stack **b)
{
	printf("===>a:\n");
	if (graphic_print(a))
		stack_print(a);
	else
		print_list(*a);
	printf("\n===>b:\n");
	if (graphic_print(b))
		stack_print(b);
	else
		print_list(*b);
	printf("\n%s\n", ok_ko(a, b));
}
