/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:31:21 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/08 17:15:03 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	while (dst[i] != 0 && i < dstsize)
		i++;
	while (src[j] != 0)
		j++;
	k = i + j;
	if (dst[i] == 0)
	{
		j = 0;
		while ((i + j) < (dstsize - 1) && src[j] != 0)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = 0;
	}
	return (k);
}
