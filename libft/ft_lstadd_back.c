/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:37:18 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/12 22:35:24 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *aux;

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
