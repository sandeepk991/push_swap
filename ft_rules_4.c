/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <skaur@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:37:39 by skaur             #+#    #+#             */
/*   Updated: 2023/06/17 11:00:39 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverserotate(t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	if (*stack_a == 0 || (*stack_a)->next == 0)
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
	if (ft_reverserotate(stack_a) == -1)
		return (-1);
	else
		write(1, "rra\n", 4);
	return (0);
}

int	ft_rrb(t_list **stack_b)
{
	if (ft_reverserotate(stack_b) == -1)
		return (-1);
	else
		write(1, "rrb\n", 4);
	return (0);
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	ft_reverserotate(stack_a);
	ft_reverserotate(stack_b);
	write(1, "rrr\n", 4);
	return (0);
}
