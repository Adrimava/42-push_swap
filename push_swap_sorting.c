#include "checker.h"

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

void    push_swap_sorter(t_stack **a, t_stack **b)
{
    int min_position;
    int a_size;

    if (*a)
    {
        a_size = list_size(*a);
        min_position = minimum_number_position(a);
        if (a_size - min_position > a_size / 2)
        {
            while (min_position-- > 1)
            {
				ra_rb(a);
				printf("ra\n");
            }
        }
        else
        {
			while (min_position++ <= a_size)
            {
				rra_rrb(a);
				printf("rra\n");
            }            
        }
		pa_pb(a,b);
    }
}