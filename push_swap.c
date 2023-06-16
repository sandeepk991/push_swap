#include "push_swap.h"
#include<stdio.h>

void print_stack(t_list *stack) {
    while (stack != NULL) {
        printf("%d ", stack->data); // Assuming the data type is int
        stack = stack->next;
    }
    printf("\n");
}

static void	fill_in_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	int	i;
	
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
static void	push_swap(int argc, char **argv)
{
	
	//printf("h\n");	
	t_list	**stack_a;
	t_list	**stack_b;
	
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_in_stack(stack_a, argc, argv);
	ft_index_stack(stack_a);
	if (is_stack_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return ;
	}
	sorting(stack_a, stack_b);
	print_stack(*stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	if (argc <= 2)
		return (-1);
	else
		ft_conditions(argc, argv);
	//printf("h\n");
	push_swap(argc, argv);
	return (0);
}

