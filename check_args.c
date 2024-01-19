/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <skaur@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:26:47 by skaur             #+#    #+#             */
/*   Updated: 2023/06/23 11:27:46 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdio.h>

char	*ft_join_arguments(char *s1, char *s2);
int		ft_isnum(char *num);
int		ft_duplicate(int num, char **argv, int i);
int		check_args(long tmp, char **args, int i);

char	**ft_conditions(int argc, char **argv)
{
	char	*arg;
	char	**args;
	int		i;

	i = 1;
	arg = ft_calloc(1, sizeof(char));
	if (!arg)
		return (NULL);
	while (i < argc)
	{
		arg = ft_join_arguments(arg, argv[i]);
		if (i < argc -1)
			arg = ft_join_arguments(arg, " ");
		i++;
	}
	args = ft_split(arg, ' ');
	free(arg);
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
	if (num[0] == '-' || num[0] == '+')
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
	if (tmp < -2147483648 || tmp > 2147483647)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (!ft_isnum(args[i]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (ft_duplicate(tmp, args, i))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

char	*ft_join_arguments(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}
