/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:44:13 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/21 19:20:27 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		a_min(t_stack **a)
{
	t_stack	*tmp;
	int		min;

	min = (*a)->number;
	tmp = *a;
	while (tmp)
	{
		if (tmp->number < min)
			min = tmp->number;
		tmp = tmp->next;
	}
	return min;	
}

int		a_max(t_stack **a)
{
	t_stack	*tmp;
	int		max;

	max = (*a)->number;
	tmp = *a;
	while (tmp)
	{
		if (tmp->number > max)
			max = tmp->number;
		tmp = tmp->next;
	}
	return max;	
}

void    push_swap(int size,  char **params)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init(size, params);
	b = NULL;
	if (a)
	{
		push_swap_sorter(&a, &b, a_min(&a), a_max(&a));
	}
	free_list(&a);
	free_list(&b);
}

int     main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	push_swap(argc - 1, argv + 1);
}
