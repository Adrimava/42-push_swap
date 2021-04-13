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

t_stack	*new_stack(int content)
{
	t_stack	*new_stack;

	if (!(new_stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new_stack->number = content;
	new_stack->next = NULL;
	return (new_stack);
}

int		*num_filler(int size,  char **params) {
	int	*numbers;
	int i;

	if (!(numbers = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (*params)
	{
		numbers[i++] = atoi(*params);
		new_stack(atoi(*params++));
	}

	return (numbers);
}

int		main(int argc, char **argv)
{
	int *numbers;

	if (argc == 1)
		return (0);
	numbers = num_filler(argc - 1, ++argv);	
}

