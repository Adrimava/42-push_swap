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

int		array_length(char **arr)
{
	int	length;

	length = 0;
	while (arr[length])
		length++;
	return (length);
}

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

int		no_repeated_numbers(char **arr)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < array_length(arr) - 1)
	{
		j = i;
		while (++j < array_length(arr))
		{
			if (!ft_strcmp(arr[i], arr[j]))
				return (0);
		}
		i++;
	}
	return (1);
}

int		param_validator(char *str)
{
	char	**params_split;

	if (!all_numbers_and_spaces(str))
		return (0);
	params_split = ft_split(str, ' ');
	if (!no_repeated_numbers(params_split))
		return (0);
	/**
	 * TODO: negative numbers.
	 * TODO: bigger than int.
	 */
	return (1);
}
