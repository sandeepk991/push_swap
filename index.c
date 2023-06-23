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

char	**ft_conditions(int argc, char **argv)
{
	char	**args;
	int		i;
	long	tmp;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (NULL);
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		check_args(tmp, args, i);
		i++;
	}
	return (args);
}

int	ft_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(long tmp, char **args, int i)
{
	tmp = ft_atoi(args[i]);
	if (tmp < -2147483648 || tmp > 2147483647)
		ft_error("Error");
	else if (!ft_isnum(args[i]))
		ft_error("Error");
	else if (ft_duplicate(tmp, args, i))
		ft_error("Error");
	return (args);
}
