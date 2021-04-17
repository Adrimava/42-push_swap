/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:59:13 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/11 16:29:19 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*sd;
	const char	*ss;

	if (src == NULL && dst == NULL)
		return (NULL);
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
