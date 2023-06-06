#include "push_swap.h"

static int	get_min(t_list **stack_a, int val)
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

static void	sort_3_args(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_stack_sorted(stack_a))
		return ;
	sort_3(stack_a, head, min, next_min);
}

static void	sort_4_args(t_list **stack_a, t_list **stack_b)
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

void	sorting(t_list **stack_a, t_list **stack_b)
{
	int	size;
	
	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		sort_3_args(stack_a);
	else if (size == 4)
		sort_4_args(stack_a, stack_b);
	else if (size == 5)
		sort_5_args(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
/*void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_stack_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_2_args(stack_a);
	else if (size == 3)
		sort_3_args(stack_a);
	else if (size == 4)
		sort_4_args(stack_a, stack_b);
	else if (size == 5)
		sort_5_args(stack_a, stack_b);
}*/
