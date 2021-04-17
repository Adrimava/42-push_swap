/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:15:33 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/05 21:42:54 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int			i;
	char		*sd;
	const char	*ss;

	ss = src;
	i = 0;
	while (i < n)
	{
		if (*ss == c)
			return (dst + 1);
		dst++;
		ss++;
		i++;
	}
	return (NULL);
}

int		main(void)
{
	char *src = "12345678912345678901234567890";
	char dst[30] = "Hola, me llamo Aureliano";
	void *d = dst;
	void *d2 = dst;
	const void *s = src;
	size_t n = 15;
	printf("!%s\n", ft_memccpy(d, s, '9', n));
	printf("-%s\n", memccpy(d2, s, '9', n));
}
