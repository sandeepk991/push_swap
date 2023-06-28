/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <skaur@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:16:41 by skaur             #+#    #+#             */
/*   Updated: 2023/06/17 11:09:42 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*stack_a;
	int		max;
	int		max_bits;

	stack_a = *stack;
	max = stack_a->index_value;
	max_bits = 0;
	while (stack_a != NULL)
	{
		if (stack_a->index_value > max)
			max = stack_a->index_value;
		stack_a = stack_a->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	stack = *stack_a;
	size = ft_lstsize(stack);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			stack = *stack_a;
			if (((stack->index_value >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
		i++;
	}
	return (0);
}
