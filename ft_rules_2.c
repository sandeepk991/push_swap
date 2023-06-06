#include "push_swap.h"

// Takes the first element of one stack and puts it at the top of another | pa and pb

int ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	if (*stack_b == 0)
		return (-1);
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	return (0);
}

int	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_a, stack_b) == -1)
		return (-1);
	else
		write(1, "pa\n", 3);
	return (0);
}

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_b, stack_a) == -1)
		return (-1);
	else
		write(1, "pb\n", 3);
	return (0);
}
