/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:01:01 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/11 17:24:23 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(unsigned int un)
{
	unsigned int	size;

	size = 1;
	while (un >= 10)
	{
		un /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	un;
	unsigned int	i;
	unsigned int	size;

	if (n < 0)
		un = (unsigned int)(n * -1);
	else
		un = (unsigned int)n;
	size = ft_size(un);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (NULL);
	i = 0;
	if (n < 0 && (str[i] = '-'))
		size++;
	i = size - 1;
	while (un >= 10)
	{
		str[i--] = (char)(un % 10 + '0');
		un /= 10;
	}
	str[i] = (char)(un % 10 + '0');
	str[size] = 0;
	return (str);
}
