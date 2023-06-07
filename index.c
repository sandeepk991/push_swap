
#include "push_swap.h"

/*static t_list	*get_next_min(t_list **stack)
{
	t_list	*stack_a;
	t_list	*min;
	int		flag;

	min = NULL;
	flag = 0;
	stack_a = *stack;
	if (stack_a != NULL)
	{
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
	}
	return (min);
}*/

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index_value == -1) && (!has_min || head->data < min->data))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
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
