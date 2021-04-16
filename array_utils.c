/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:47:34 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/16 17:40:29 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		str_array_length(char **arr)
{
	int	length;

	length = 0;
	while (arr[length])
		length++;
	return (length);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (i < str_array_length(arr))
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
