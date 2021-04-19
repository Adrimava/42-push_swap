/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:44:13 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/19 18:52:11 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    push_swap(int size,  char **params)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init(size, params);
	b = NULL;
	if (a)
	{
		push_swap_sorter(&a, &b);
		result(&a, &b);
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
