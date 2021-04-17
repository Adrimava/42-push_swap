/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:45:55 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/12 19:02:46 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*aux;

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
