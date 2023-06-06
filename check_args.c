
#include "push_swap.h"
static int	ft_duplicate(int num, char **argv, int i);
static int	ft_nonnum(char *num);

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error");
		else if (!ft_nonnum(args[i]) || ft_duplicate(tmp, args, i))
			ft_error("Error");
	}
	if (argc == 2)
		ft_free(args);
}

static int	ft_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_nonnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i] != '\0')
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}
