/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:44:51 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/16 18:20:45 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strdup(const char *s1)
{
	int					i;
	unsigned long int	l;
	char				*s;

	i = 0;
	l = ft_strlen(s1);
	s = (char*)malloc(sizeof(char) * (l + 1));
	if (s == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
