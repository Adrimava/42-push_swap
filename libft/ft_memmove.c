/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:37:24 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/11 16:36:35 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*s1;
	const unsigned char	*s2;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	s1 = (unsigned char*)dst;
	s2 = (const unsigned char*)src;
	if (s2 < s1)
		while (++i <= len)
			s1[len - i] = s2[len - i];
	else
	{
		while (len > 0)
		{
			*(s1++) = *(s2++);
			len--;
		}
	}
	return (dst);
}
