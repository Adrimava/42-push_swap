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
