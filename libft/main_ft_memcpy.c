/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:59:13 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/05 20:58:50 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*sd;
	const char	*ss;

	sd = dst;
	ss = src;
	i = 0;
	while (i < n)
	{
		*sd = *ss;
		sd++;
		ss++;
		src++;
		i++;
	}
	return (dst);
}

int		main(void)
{
	char *src = "12345678912345678901234567890";
	char dst[30] = "Hola, me llamo Aureliano";
	void *d = dst;
	void *d2 = dst;
	const void *s = src;
	size_t n = 5;
	printf("!%s\n", ft_memcpy(d, s, n));
	printf("-%s\n", memcpy(d2, s, n));
}
