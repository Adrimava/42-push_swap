/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:37:24 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/06 12:18:49 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int					i;
	unsigned char		*s1;
	const unsigned char	*s2;

	i = 1;
	s1 = (unsigned char*)dst;
	s2 = (const unsigned char*)src;
	if (s1 < s2)
	{
		while (i < len)
		{
			s1[len - i] = s2[len - i];
			i++;
		}
	}
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

int		main(void)
{
	char		d[20] = "Hola";
	void		*dst = d;
	void		*ds2 = d;

	const void	*src = "Mundo 1234567890";
	printf("!%s\n", ft_memmove(dst, src, 30));
	printf("-%s\n", memmove(dst, src, 30));
}
