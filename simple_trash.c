#include "push_swap.h"
#include<stdio.h>

void	sort_3_args(t_list **stack_a);
void 	print_stack(t_list *stack);
/*static void	sort_4_args(t_list **stack_a, t_list **stack_b);

static int	get_min(t_list **stack_a, int val)
{
	t_list	*head;
	int		min;

	head = *stack_a;
	min = head->index_value;
	while (head->next)
	{
		head = head->next;
		if ((head->index_value < min) && head->index_value != val)
			min = head->index_value;
	}
	return (min);
}*/

/*static void	sort_3_args(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_stack_sorted(stack_a))
		return ;
	sort_3(stack_a, head, min, next_min);
}*/

 void	sort_3_args(t_list **stack_a)
{
	int	x;
	int	y;
	int	z;
	
	while (!(x < y && y < z && z > x))
	{
		x = (*stack_a)->data;
		y = (*stack_a)->next->data;
		z = (*stack_a)->next->next->data;
		if (x < y && y > z && z < x)
			ft_rra(stack_a);
		if (x > y && y < z && z < x)
			ft_ra(stack_a);
		if ((x > y && y > z && z < x) || (x > y && y < z && z > x)
			|| (x > y && y > z && z < x) || (x < y && y > z && z > x))
			ft_sa(stack_a);
	}
}

/*void	sort_upto_5_args(t_list **stack_a, t_list **stack_b)
{
	int	i;
	
	i = 2;
	while (i > 0)
	{
		ft_pb(stack_a, stack_b);
		i--;
	}
	sort_3_args(sack_a);
	
}*/



/*void	sort_head(int *head, int size)
{
	int	x;
	int	y;
	int	z;
	
	x = 0;
	while (x < size -1)
	{
		y = x + 1;
		while (y < size)
		{
			if (head[x] > head[y])
			{
				z = head[x];
				head[x] = head[y];
				head[y] = z;
			}
			y++;
		}
		x++;
	}
}

int	*put_data_in_head(t_list *stack_a, int size)
{
	int	*a;
	int	i;
	
	a = (int *) malloc (size * sizeof(int));
	if (!a)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size && stack_a)
	{
		a[i] = stack_a->data;
		i++;
		stack_a = stack_a->next;
	}
	return (a);
}*/

/*void	sort_4to5_args(t_list **stack_a, t_list **stack_b)
{
	//int	*head;
	int	i;
	int size_a;
	
	i = 0;
	size_a = ft_lstsize(*stack_a);
	//head = put_data_in_head(*stack_a, ft_lstsize(*stack_a));
	//sort_head(head, i);
	//printf("size of stack in sort_4to5_args : %i\n", ft_lstsize(*stack_a));
	while (i < size_a)
	{
		//printf("size_a: %i\n", ft_lstsize(*stack_a));
		if (i == 3 || i == 4)
		{
			ft_pb(stack_a, stack_b);
		}
		else
		{
			ft_ra(stack_a);
		}
		i++;
	}
	sort_3_args(stack_a);
	i = 3;
	while (i++ <= size_a)
	{
		
		//printf("size_a: %i\n", ft_lstsize(*stack_a));
		ft_pa(stack_a, stack_b);
	}	
}*/

int	*put_data_in_head(t_list *stack_a, int size)
{
	int	*a;
	int	i;
	
	a = (int *) malloc (size * sizeof(int));
	if (!a)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size && stack_a)
	{
		a[i] = stack_a->data;
		i++;
		stack_a = stack_a->next;
	}
	return (a);
}

void sort_4to5_args(t_list **stack_a, t_list **stack_b)
{
    int size_a = ft_lstsize(*stack_a);
    int i = 0;

    while (i < size_a)
    {
        if (i>= 0  && (*stack_a)->index_value == 0)
        {
            ft_pb(stack_a, stack_b);
        }
        else
        {
            ft_ra(stack_a);
        }
        i++;
    }
    sort_3_args(stack_a);
    i = 0;
    while (i < size_a - 3)
    {
        ft_pa(stack_a, stack_b);
        i++;
    }
}

void sort_upto_5_args(t_list **stack_a, t_list **stack_b) 
{
    int *head;
    int i;
    int size_a;
    int flag;
    int max_iterations = 4; // Set a maximum number of iterations
    
    flag = 0;
    
    head = put_data_in_head(*stack_a, 5);
    while (!is_stack_sorted(stack_a) && max_iterations > 0)
    {
        size_a = ft_lstsize(*stack_a);
        //printf("i am at the start of if stmt\n");
        if (!flag)
        {
            sort_4to5_args(stack_a, stack_b);
            //printf("i am in if stmt\n");
            flag = 1;
            //print_stack(*stack_a);
        }
        else 
        {
            if (size_a == 5 && head[0] > head[1])
                ft_sa(stack_a);
            i = 0;
            //printf("size_a: %i\n", size_a);
            while (i < size_a -4)
            {
                ft_ra(stack_a);
                //print_stack(*stack_a);
                i++;
            }
        }
        max_iterations--;
        //printf("i am stuck in while loop\n");
         //printf("i am out of if stmt\n");
    }
}


/*void sort_upto_5_args(t_list **stack_a, t_list **stack_b) 
{
    int *head;
    int i;
    int	size_a;
    int flag;
    
    flag = 0;
    
    head = put_data_in_head(*stack_a, 5);
    while (!is_stack_sorted(stack_a))
    {
    	 size_a = ft_lstsize(*stack_a);
    	 printf("i am at the start of if stmt\n");
    	if (!flag)
    	{
    		sort_4to5_args(stack_a, stack_b);
    		printf("i am in if stmt\n");
    		flag = 1;
    		//print_stack(*stack_a);
        }
        else 
        {
        	if (size_a == 5 && head[0] > head[1])
        		ft_sa(stack_a);
        	i = 3;
        	printf("size_a: %i\n", size_a);
        	while (i < size_a && !(is_stack_sorted(stack_a)))
        	{
        		ft_ra(stack_a);
        		i++;
        	}
        }
        //printf("i am stuck in while loop\n");
         //printf("i am out of if stmt\n");
    }
}
*/
int get_max(t_list *stack)
{
    int max_val = stack->data;
    stack = stack->next;
    
    while (stack)
    {
        if (stack->data > max_val)
            max_val = stack->data;
        stack = stack->next;
    }
    
    return max_val;
}
/*void sort_upto_5_args(t_list **stack_a, t_list **stack_b)
{
    int flag = 0;
  
    while (!is_stack_sorted(stack_a))
    {
        if (!flag)
        {
            sort_4to5_args(stack_a, stack_b);
            flag = 1;
        }
        else
        {
            //printf("i am at the start of if stmt\n");
            if (ft_lstsize(*stack_a) == 5)
            {
                int max_val = get_max(*stack_a);
                if ((*stack_a)->data > (*stack_a)->next->data || (*stack_a)->data == max_val)
                    ft_sa(stack_a);
                else if ((*stack_a)->next->data == max_val)
                    ft_rra(stack_a);
                else if ((*stack_a)->next->next->data == max_val)
                {
                    ft_sa(stack_a);
                    ft_sa(stack_a);
                }
            }
            while (*stack_b)
                ft_pa(stack_a, stack_b);
        }
    }
}

*/


/*void sort_upto_5_args(t_list **stack_a, t_list **stack_b)
{
    int flag = 0;
  
    while (!is_stack_sorted(stack_a))
    {
        if (!flag)
        {
            sort_4to5_args(stack_a, stack_b);
            flag = 1;
        }
        else
        {
            //printf("i am at the start of if stmt\n");
            if (ft_lstsize(*stack_a) == 5)
            {
                int max_val = get_max(*stack_a);
                if ((*stack_a)->data > (*stack_a)->next->data || (*stack_a)->data == max_val)
                    ft_sa(stack_a);
                else if ((*stack_a)->next->data == max_val)
                    ft_rra(stack_a);
                else if ((*stack_a)->next->next->data == max_val)
                {
                    ft_sa(stack_a);
                    ft_sa(stack_a);
                }
            }
            while (*stack_b)
                ft_pa(stack_a, stack_b);
        }
    }
}

*/
/* only sorts 4 elements so far
void sort_upto_5_args(t_list **stack_a, t_list **stack_b) 
{
    //int *head;
    int i;
    int	size_a;
    int flag;
    
    flag = 0;
    size_a = ft_lstsize(*stack_a);
    //head = put_data_in_head(*stack_a, 5);
    while (!is_stack_sorted(stack_a))
    {
    	 printf("i am at the start of if stmt\n");
    	if (!flag)
    	{
    		sort_4to5_args(stack_a, stack_b);
    		printf("i am in if stmt\n");
    		flag = 1;
    		//print_stack(*stack_a);
        }
        else 
        {
        	if (size_a == 5 && (*stack_a)->data > (*stack_a)->next->data)
        		ft_sa(stack_a);
        	i = 3;
        	printf("size_a: %i\n", size_a);
        	while (i < size_a)
        	{
        		ft_ra(stack_a);
        		i++;
        	}
        }
        //printf("i am stuck in while loop\n");
         //printf("i am out of if stmt\n");
    }
}
*/

/*void	sort_325_args(t_list **stack_a, t_list **stack_b)
{
	
}

void	sort_upto_325_args(t_list **stack_a, t_list **stack_b)
{
	t_list *head;
	
	head = *stack_a;
	if (ft_lstsize(*stack_a) == 5 && head->data > head->next->data)
		
}*/
/*static void	sort_4_args(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_stack_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
		ft_rra(stack_a);
	if (is_stack_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	sort_3_args(stack_a);
	ft_pa(stack_a, stack_b);
}

void	sort_5_args(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (distance == 4)
		ft_rra(stack_a);
	if (is_stack_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	sort_4_args(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}*/
/*void	sorting(t_list **stack_a, t_list **stack_b)
{
	int	size;
	
	if (is_stack_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		sort_3_args(stack_a);
	else if (size == 4)
		sort_4_args(stack_a, stack_b);
	else if (size == 5)
		sort_5_args(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}*/
void	sort_2_args(t_list **stack_a)
{
	t_list *head;
	
	head = *stack_a;
	if (head->data > head->next->data)
		ft_sa(stack_a);
	
}

/*int	*put_data_in_head(t_list *stack_a, int size)
{
	int	*a;
	int	i;
	
	a = (int *) malloc (size * sizeof(int));
	if (!a)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size && stack_a)
	{
		a[i] = stack_a->data;
		i++;
		stack_a = stack_a->next;
	}
	return (a);
}

void	sort_head(int *head, int size)
{
	int	x;
	int	y;
	int	z;
	
	x = 0;
	while (x < size -1)
	{
		y = x + 1;
		while (y < size)
		{
			if (head[x] > head[y])
			{
				z = head[x];
				head[x] = head[y];
				head[y] = z;
			}
			y++;
		}
		x++;
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	int	*head;
	int	i;
	
	i = 5;
	head = put_data_in_head(*stack_a, 5);
	sort_head(head, i);
	while (i > 2)
	{
		if ((*stack_a)->data == head[3] || (*stack_a)->data == head[4])
			ft_ra(stack_a);
		else
		{
			ft_pb(stack_a, stack_b);
			if((*stack_b)->data < head[1])
				ft_rb(stack_b);
			i--;
		}
	}
}

void	sort_upto_5_args(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	if ((*stack_b)->data < (*stack_b)->next->data)
		ft_sb(stack_b);
	if((*stack_a)->data > (*stack_a)->next->data)
		ft_ra(stack_a);
	while ((*stack_b))
		ft_pa(stack_a, stack_b);
}*/

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
	/*else if (size == 4)
		sort_4_args(stack_a, stack_b);*/
	else if (size <= 5)
		sort_upto_5_args(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
