/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:11 by amaza-va            #+#    #+#             */
/*   Updated: 2021/04/16 14:58:55 by amaza-va         ###   ########.fr       */
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

int		list_size(t_stack *lst)
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
