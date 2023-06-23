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

int	ft_isnum(char *num);
int	ft_duplicate(int num, char **argv, int i);
char	**check_args(long tmp, char **args, int i);

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
		tmp = ft_atoi(args[i]);
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

char	**check_args(long tmp, char **args, int i)
{

	if (tmp < -2147483648 || tmp > 2147483647)
		ft_error("Error");
	else if (!ft_isnum(args[i]))
		ft_error("Error");
	else if (ft_duplicate(tmp, args, i))
		ft_error("Error");
	return (args);
}
