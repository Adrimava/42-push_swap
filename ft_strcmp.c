/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:32:20 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/16 16:07:36 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	int				num;

	num = 0;
	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (num == 0))
	{
		num += (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (num == 0)
	{
		num = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (num);
}
