#include "push_swap.h"
#include <stdio.h>
void	print_exit(char *msg, t_list **stack_a, t_list **stack_b)
{
	ft_putendl_fd(msg, 1);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(EXIT_FAILURE);
}

/*void	print_exit(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || stack_b == NULL) {
		// Handle allocation failure
		printf("Memory allocation failed. Exiting.\n");

		// Clean up any previously allocated memory
		if (stack_a != NULL) {
			free(stack_a);
		}
		if (stack_b != NULL) {
			free(stack_b);
		}

		// Terminate the program
		exit(EXIT_FAILURE);
	}
}*/

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(EXIT_FAILURE);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}
