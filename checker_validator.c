/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:11 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/16 16:04:07 by amaza-va         ###   ########.fr       */
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

int		all_numbers_and_spaces_and_minus(char *str)
{
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || *str == ' ' || *str == '-'))
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

int		negative_numbers_validation(char **arr)
{
	int		i;
	char	*minus_position;
	
	i = 0;
	while (i < array_length(arr))
	{
		if ((minus_position = ft_strrchr(arr[i], '-')))
		{
			if (!(*(minus_position + 1) >= '0' && *(minus_position + 1) <= '9'))
				return (0);
		}
		i++;
	}
	return (1);
}

int		fit_in_int(char **arr)
{
	int		i;
	long	tmp;

	i = 0;
	while (i < array_length(arr))
	{
		tmp = ft_atol(arr[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (0);
		i++;
	}
	return (1);	
}

int		param_validator(char *str)
{
	char	**params_split;

	if (!all_numbers_and_spaces_and_minus(str))
		return (0);
	params_split = ft_split(str, ' ');
	if (!no_repeated_numbers(params_split))
		return (0);
	if (!negative_numbers_validation(params_split))
		return (0);
	if (!fit_in_int(params_split))
		return (0);
	return (1);
}
