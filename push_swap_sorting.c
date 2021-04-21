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

int     up_number_position(t_stack **a, int a_size, int min, int max)
{
	t_stack	*tmp;
	int		position;

	tmp = *a;
	position = 0;
	while (position < a_size)
	{
	    if (min <= tmp->number && tmp->number <= max)
		{
	    	return (position);
		}
		tmp = tmp->next;
	    position++;
	}
	return (position);
}

int     bottom_number_position(t_stack **a, int a_size, int min, int max)
{
	t_stack	*tmp;
	int		i;
	int		position;

	tmp = *a;
	position = 0;
	i = 0;
	while (i < a_size)
	{
	    if (min <= tmp->number && tmp->number <= max)
		{
	    	position = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (position);
}

void	push_to_b(t_stack **a, t_stack **b, int min, int max)
{
	int	up_position;
	int	bottom_position;
	int	a_size;

	a_size = list_size(*a);
    up_position = up_number_position(a, a_size, min, max);
    bottom_position = a_size - bottom_number_position(a, a_size, min, max);
	//printf("[%d]-[%d]\n", min, max);////////////////
    if (up_position < bottom_position)
    {
        while (up_position-- > 0)
        {
			printf("ra\n");
			ra_rb(a);
        }
    }
    else
    {
		while (bottom_position-- > 0)
        {
			printf("rra\n");
			rra_rrb(a);
        }            
    }
	printf("pb\n");
	pa_pb(a, b);
}

void    push_swap_sorter(t_stack **a, t_stack **b, int min, int max)
{
	int	block;
	int	block_size;
	int	i;

	block_size = ((max - min) / 10) + 1;
	block = 0;
    while (*a && block < 10)
    {
		i = 0;
		while (i < block_size)
		{
			push_to_b(a, b, min * block * block_size + min, min * (block + 1) * block_size);
			order_b(b);
			i++;
		}
		block++;
	}
	while (*b)
	{
		order_b(b);
		pa_pb(b, a);
		printf("pa\n");
	}
}
