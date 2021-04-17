/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:26:46 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/06 16:40:31 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*sc = s;
	while (*sc != 0 && n > 0)
	{
		if (*sc == c)
			return ((void *)s);
		n--;
		sc++;
	}
	if (*sc == c && n > 0)
		return ((void *)s);
	return (NULL);
}

int		main(void)
{
	const char	*s = "Hola Mundo";
	const char	*s2 = s;
	int			c = 0;
	size_t		n = 10;

	printf("!%s\n", ft_memchr(s, c, n));
	printf("-%s\n", memchr(s2, c, n));
}
