#include "push_swap.h"

// Shifts down all elements of a stack by 1. The last element becomes the first one | rra and rrb

int	ft_reverseRotate(t_list **stack_a)
{
	t_list	*tmp;
	int i;

	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	tmp = *stack_a;
	i = 0;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	return (0);
}

int	ft_rra(t_list **stack_a)
{
	if (ft_reverseRotate(stack_a) == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int	ft_rrb(t_list **stack_b)
{
	if (ft_reverseRotate(stack_b) == -1)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	ft_reverseRotate(stack_a);
	ft_reverseRotate(stack_b);
	write(1, "rrr\n", 4);
	return (0);
}

