/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:15:51 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/05 19:25:40 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *b, size_t len)
{
	unsigned char	*s;

	s = b;
	while (len > 0)
	{
		*s = 0;
		s++;
		len--;
	}
}

int	main(void)
{
	char b[15] = "Que pasa mundo";
	char *a;
	char *x;
	a = b;
	x = b;
	ft_bzero(a, 10);
	bzero(a, 10);
	printf("%s\n", a);
	printf("%s\n", x);
}
