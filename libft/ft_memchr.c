/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:26:46 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/06 18:54:19 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*sc;

	sc = s;
	while (n > 0)
	{
		if (*sc == c)
			return ((void *)sc);
		n--;
		sc++;
	}
	return (NULL);
}
