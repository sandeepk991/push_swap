#include "push_swap.h"
#include<stdio.h>



static void	init_Stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

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
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}
/*static void	sort_the_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		(stack_a);
	else
		radix_sort(stack_a, stack_b);
}*/



int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_Stack(stack_a, argc, argv);
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

//void	simple_sort(t_list **stack_a);

/*static void	write_list(t_list **stack, char **argv, int i);

static void	init_Stack(t_list **stack, int argc, char **argv)
{
	//t_list	*new;
	char	**args;
	int		i;

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
		write_list(stack, args, i);
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

static void	write_list(t_list **stack, char **argv, int i)
{
	t_list	*new;
	new = ft_lstnew(ft_atoi(argv[i]));
	ft_lstadd_back(stack, new);
	i++;
}

static void	push_swap(int argc, char **argv)
{
	
	//printf("h\n");	
	t_list	**stack_a;
	t_list	**stack_b;
	
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_Stack(stack_a, argc, argv);
	if (is_stack_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return ;
	}
	sorting(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	else
		check_args(argc, argv);
	//printf("h\n");
	push_swap(argc, argv);
	return (0);
}*/

