/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:56:52 by amaza-va          #+#    #+#             */
/*   Updated: 2021/04/19 18:09:42 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    intructions_parser2(char *instruction ,t_stack **a, t_stack **b)
{
	if (!ft_strcmp(instruction, "rra"))
        rra_rrb(a);
    else if (!ft_strcmp(instruction, "rrb"))
        rra_rrb(b);
	else if (!ft_strcmp(instruction, "rrr"))
	{
        rra_rrb(a);		
        rra_rrb(b);		
	}
    else
        printf("Error\nPlease, write a valid instruction.\n");
}


void    intructions_parser(char *instruction ,t_stack **a, t_stack **b)
{
    if (!ft_strcmp(instruction, "sa"))
        sa_sb(a);
    else if (!ft_strcmp(instruction, "sb"))
        sa_sb(b);
	else if (!ft_strcmp(instruction, "ss"))
	{
		sa_sb(a);
        sa_sb(b);
	}
    else if (!ft_strcmp(instruction, "pa"))
        pa_pb(b, a);
    else if (!ft_strcmp(instruction, "pb"))
        pa_pb(a, b);
    else if (!ft_strcmp(instruction, "ra"))
        ra_rb(a);
    else if (!ft_strcmp(instruction, "rb"))
        ra_rb(b);
    else if (!ft_strcmp(instruction, "rr"))
	{
        ra_rb(a);
        ra_rb(b);		
	}
	else
		intructions_parser2(instruction, a, b);
}

void	checker_user_input(t_stack **a, t_stack **b)
{
	char	*instructions;

	printf("Please, write the instructions:\n");
	while (get_next_line(0, &instructions) > 0) {
		if(!ft_strcmp(instructions, ""))
			break;
        intructions_parser(instructions, a, b);
		free(instructions);
	}
	free(instructions);
}
