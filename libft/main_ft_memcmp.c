/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:45:17 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/06 12:56:05 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			i;
	const char	*c1;
	const char	*c2;

	c1 = s1;
	c2 = s2;
	i = 0;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	const char	*c1 = "Hola \0Mundp";
	const char	*c2 = "Hola \0Mundq";
	const void	*s1 = c1;
	const void	*s2 = c2;
	size_t		n = 25;

	printf("!%d\n", ft_memcmp(s1, s2, n));
	printf("!%d\n", memcmp(s1, s2, n));
}
