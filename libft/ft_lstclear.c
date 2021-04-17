/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:39:30 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/12 22:36:23 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*next;

	aux = *lst;
	if (aux)
	{
		while (aux)
		{
			next = aux->next;
			del(aux->content);
			free(aux);
			aux = next;
		}
		*lst = NULL;
	}
}
