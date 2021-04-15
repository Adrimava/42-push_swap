/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:11 by marvin            #+#    #+#             */
/*   Updated: 2021/04/12 17:59:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		all_numbers_and_spaces(char *str)
{
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || *str == ' '))
			return (0);
		str++;
	}
	return (1);	
}

int		param_validator(char *str)
{
	if (!all_numbers_and_spaces(str))
		return (0);
	/**
	 * TODO: concat params.
	 * TODO: repeated_numbers.
	 * TODO: bigger than int.
	 */
	return (1);
}
