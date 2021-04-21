#include "checker.h"

int     max_number_position(t_stack **b)
{
	t_stack	*tmp;
	int		max;
	int		position;
	int		i;

	tmp = *b;
	max = (*b)->number;
	position = 1;
	i = 1;
	while (list_size(tmp) > 0)
	{
	    if (max < (tmp)->number)
	    {
	        max = (tmp)->number;
	        position = i;
	    }
		tmp = (tmp)->next;
	    i++;
	}
	return (position);
}

void	order_b(t_stack **b)
{
	int	max_position;
	int	b_size;

	b_size = list_size(*b);
    max_position = max_number_position(b);
    if (b_size - max_position > b_size / 2)
    {
        while (max_position-- > 1)
        {
			printf("rb\n");
			ra_rb(b);
        }
    }
    else
    {
		while (max_position++ <= b_size)
        {
			printf("rrb\n");
			rra_rrb(b);
        }            
    }
}
