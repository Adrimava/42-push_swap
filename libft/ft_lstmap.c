/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:55:13 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/12 23:32:41 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*aux;
	t_list	*first;

	if (!lst)
		return (NULL);
	if (!(aux = ft_lstnew(f(lst->content))))
		return (NULL);
	first = aux;
	while (lst)
	{
		if (lst->next)
		{
			if (!(aux->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&first, del);
				return (0);
			}
			aux = aux->next;
		}
		lst = lst->next;
	}
	aux->next = NULL;
	return (first);
}
