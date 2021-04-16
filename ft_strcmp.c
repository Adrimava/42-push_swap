/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:32:20 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/14 16:20:29 by amaza-va         ###   ########.fr       */
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
	return (num);
}
