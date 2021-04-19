/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:11 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/19 18:03:11 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*join_params(char **params, int size)
{
	char	*tmp;
	char	*tmp2;
	char	*params_str;
	int		i;

	params_str = ft_strjoin(params[0], " ");
	i = 0;
	while (++i < size)
	{
		tmp = ft_strjoin(params[i], " ");
		tmp2 = params_str;
		params_str = ft_strjoin(params_str, tmp);
		free(tmp);
		free(tmp2);
	}
	return(params_str);
}

t_stack	*stack_filler(char **numbers_arr)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		i;

	stack = NULL;
	i = 0;
	while (i < str_array_length(numbers_arr))
	{
		tmp = new_stack(ft_atoi(numbers_arr[i]));
		stack_add_back(&stack, tmp);
		i++;
	}
	
	free_array(numbers_arr);
	return stack;	
}

t_stack	*stack_init(int size,  char **params)
{
	char	*params_str;
	char	**numbers_arr;

	params_str = join_params(params, size);
	numbers_arr = param_validator(params_str);
	free(params_str);
	if (!numbers_arr)
	{
		printf("Error\n");
		return (NULL);
	}
	return (stack_filler(numbers_arr));
}
