/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <skaur@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:16:02 by skaur             #+#    #+#             */
/*   Updated: 2023/06/23 16:31:14 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_isnum(char *num);
int	ft_duplicate(int num, char **argv, int i);

static t_list	*get_next_min(t_list **stack)
{
	t_list	*stack_a;
	t_list	*min;
	int		flag;

	min = NULL;
	flag = 0;
	stack_a = *stack;
	while (stack_a != NULL)
	{
		if (stack_a->index_value == -1)
		{
			if (!flag || stack_a->data < min->data)
			{
				min = stack_a;
				flag = 1;
			}
		}
		stack_a = stack_a->next;
	}
	return (min);
}

void	ft_index_stack(t_list **stack)
{
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = get_next_min(stack);
	while (stack_a)
	{
		stack_a->index_value = i++;
		stack_a = get_next_min(stack);
	}
}
