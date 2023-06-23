/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <skaur@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:23:38 by skaur             #+#    #+#             */
/*   Updated: 2023/06/23 11:39:50 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdio.h>

void	print_exit(char *msg, t_list **stack_a, t_list **stack_b);

static void	fill_in_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	int		i;

	i = 1;
	if (argc > 2)
	{
		while (argv[i])
		{
			new = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_back(stack, new);
			i++;
		}
	}
	ft_index_stack(stack);
	if (argc == 2)
		ft_free(argv);
}

void	sorting(t_list **stack_a, t_list **stack_b)
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
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (stack_a == NULL || stack_b == NULL)
		print_exit("malloc fail", stack_a, stack_b);
	*stack_a = NULL;
	*stack_b = NULL;
	if (argc <= 2)
		return (0);
	ft_conditions(argc, argv);
	fill_in_stack(stack_a, argc, argv);
	if (is_stack_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sorting(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
