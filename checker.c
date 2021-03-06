/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:11 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/19 18:03:11 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(int size,  char **params)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init(size, params);
	b = NULL;
	if (a)
	{
		checker_user_input(&a, &b);
		result(&a, &b);
	}
	free_list(&a);
	free_list(&b);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	checker(argc - 1, argv + 1);
}
