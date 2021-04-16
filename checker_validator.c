/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:11 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/16 19:26:53 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	while (i < str_array_length(arr) - 1)
	{
		j = i;
		while (++j < str_array_length(arr))
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
	char	*minus_pos;
	
	i = 0;
	while (i < str_array_length(arr))
	{
		if ((minus_pos = ft_strchr(arr[i], '-')))
		{
			if (!(*(minus_pos + 1) >= '0' && *(minus_pos + 1) <= '9'))
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
	while (i < str_array_length(arr))
	{
		tmp = ft_atol(arr[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (0);
		i++;
	}
	return (1);	
}

char	**param_validator(char *str)
{
	char	**params_split;

	if (!all_numbers_and_spaces_and_minus(str))
		return (NULL);
	params_split = ft_split(str, ' ');
	if (!no_repeated_numbers(params_split))
		return (NULL);
	if (!negative_numbers_validation(params_split))
		return (NULL);
	if (!fit_in_int(params_split))
		return (NULL);
	return (params_split);
}
