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

void	checker(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	printf("a//\n");			////Just for testing, delete.
	print_list(a);				////Just for testing, delete.
	printf("b//\n");			////Just for testing, delete.
	print_list(b);				////Just for testing, delete.
	// sa_sb(&a);				////Just for testing, delete.
	pa_pb(&a, &b);				////Just for testing, delete.
	// ra_rb(&a);				////Just for testing, delete.
	rra_rrb(&b);				////Just for testing, delete.
	printf("a///////\n");		////Just for testing, delete.
	print_list(a);				////Just for testing, delete.
	printf("b///////\n");		////Just for testing, delete.
	print_list(b);				////Just for testing, delete.
}
