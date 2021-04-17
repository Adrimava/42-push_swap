/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:19:11 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/05 18:03:36 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = b;
	while (len > 0)
	{
		*s = c;
		s++;
		len--;
	}
	return (b);
}

int	main(void)
{
	char b[15] = "Que pasa mundo";
	char *a;
	a = b;
	printf("%s\n", ft_memset(a, '1', 10));
	printf("%s\n", memset(a, '1', 10));
}
