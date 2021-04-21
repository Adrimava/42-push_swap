#include "checker.h"

int		is_sorted(t_stack **a)
{
	int		i;
	t_stack	*tmp;
	
	tmp = *a;
	i = 0;
	while (i < list_size(*a) - 1)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);	
}

int     minimum_number_position(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		position;
	int		i;

	tmp = *a;
	min = (*a)->number;
	position = 1;
	i = 1;
	while (list_size(tmp) > 0)
	{
	    if (min > (tmp)->number)
	    {
	        min = (tmp)->number;
	        position = i;
	    }
		tmp = (tmp)->next;
	    i++;
	}
	return (position);
}

void	push_minimum_to_b(t_stack **a, t_stack **b)
{
	int	min_position;
	int	a_size;

	a_size = list_size(*a);
    min_position = minimum_number_position(a);
    if (a_size - min_position > a_size / 2)
    {
        while (min_position-- > 1)
        {
			printf("ra\n");
			ra_rb(a);
        }
    }
    else
    {
		while (min_position++ <= a_size)
        {
			printf("rra\n");
			rra_rrb(a);
        }            
    }
	printf("pb\n");
	pa_pb(a, b);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	if (list_size(*b) > 0)
	{
		printf("pa\n");
		pa_pb(b, a);
	}
}

void    push_swap_sorter(t_stack **a, t_stack **b)
{
    while (*a)
    {
		if (is_sorted(a))
			break;
		push_minimum_to_b(a, b);
	}
	while (*b)
	{
		printf("pa\n");
		push_to_a(a, b);
	}
}
