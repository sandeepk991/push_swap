#include "push_swap.h"


void	sort_3_args(t_list **stack_a);
void	sort_4_args(t_list **stack_a, t_list **stack_b);

int	get_min(t_list **stack_a, int val)
{
	t_list	*head;
	int		min;

	head = *stack_a;
	min = head->index_value;
	while (head->next)
	{
		head = head->next;
		if ((head->index_value < min) && head->index_value != val)
			min = head->index_value;
	}
	return (min);
}

void	sort_2_args(t_list **stack_a)
{
	t_list *head;
	
	head = *stack_a;
	if (head->data > head->next->data)
		ft_sa(stack_a);
}

void	sort_3_args(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_stack_sorted(stack_a))
		return ;
	if (head->index_value == min && head->next->index_value != next_min)
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

void	sort_4_args(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_stack_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
		ft_rra(stack_a);
	if (is_stack_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	sort_3_args(stack_a);
	ft_pa(stack_a, stack_b);
}

void	sort_5_args(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (distance == 4)
		ft_rra(stack_a);
	if (is_stack_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	sort_4_args(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
