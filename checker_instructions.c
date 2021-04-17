/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:11 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/17 21:34:30 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	pa_pb(t_stack **to_be_taken, t_stack**to_be_added)
{
	t_stack *tmp;

	if (*to_be_taken)
	{
		tmp = *to_be_taken;
		*to_be_taken = (*to_be_taken)->next;
		stack_add_to_front(to_be_added, tmp);
	}
}

void	ra_rb(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack) 
	{
		tmp = *stack;
		*stack = (*stack)->next;
		ft_lstadd_back(stack, tmp);
	}
}

void	rra_rrb(t_stack **stack)
{
	t_stack	*last;
	t_stack *aux;

	if (*stack && list_size(*stack) > 1) 
	{
		last = ft_lstlast(*stack);
		aux = *stack;
		while (aux->next != last)
		{
			aux = aux->next;
		}
		aux->next = NULL;
		stack_add_to_front(stack, last);
	}
}
