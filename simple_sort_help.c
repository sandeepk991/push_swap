#include "push_swap.h"

void	sort_3(t_list **stack_a, t_list *head, int min, int next_min)
{
	if (head->next->index_value != next_min && head->index_value == min)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (head->index_value == next_min)
	{
		if (head->next->index_value == min)
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
	}
	else
	{
		if (head->next->index_value == min)
			ft_ra(stack_a);
		else
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
	}
}

