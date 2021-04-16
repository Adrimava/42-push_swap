/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:31:35 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/16 21:51:42 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_list(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *tmp2;
	int		i;

	tmp = *stack;
	i = 0;
	while (i < list_size(*stack))
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
		i++;
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
		i++;
	}
	return ("OK");	
}

void	result(t_stack **a, t_stack **b)
{
	printf("===>a:\n");
	print_list(*a);
	printf("===>b:\n");
	print_list(*b);
	printf("%s\n", ok_ko(a, b));
}
