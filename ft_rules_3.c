#include "push_swap.h"

// Shift up all elements of a stack by 1. The first element becomes the last one | ra and rb

int	ft_rotate(t_list **stack_a)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	tmp = *stack_a;
	*stack_a = ft_lstlast(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	return (0);
}

int	ft_ra(t_list **stack_a)
{
	if (ft_rotate(stack_a) == -1)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

int	ft_rb(t_list **stack_b)
{
	if (ft_rotate(stack_b) == -1)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
	return (0);
}
