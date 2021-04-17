/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:53:54 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/11 22:23:15 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstck, const char *ndl, size_t len)
{
	char	*pajar;
	char	*aguja;
	size_t	i;
	size_t	j;

	aguja = (char *)ndl;
	pajar = (char *)hstck;
	i = 0;
	if (aguja[i] == 0)
		return (pajar);
	while (i < len && pajar[i] != 0)
	{
		j = 0;
		while (i + j < len && aguja[j] == pajar[i + j])
		{
			if (pajar[i + j] == 0 || aguja[j + 1] == 0)
				return (&pajar[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
