#include "push_swap.h"

// Swaps first two elements of a stack | sa and sb

int ft_swap(t_list **stack_a)
{
	t_list *tmp;
	if (*stack_a == NULL || (*stack_a)->next)
		return (-1);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	return (0);
}

int	ft_sa(t_list **stack_a)
{
	if (ft_swap(stack_a) == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	ft_sb(t_list **stack_b)
{
	if (ft_swap(stack_b) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ft_ss(t_list **stack_a, t_list **stack_b)
{	
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
	return (0);
}

