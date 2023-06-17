/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <skaur@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:17:33 by skaur             #+#    #+#             */
/*   Updated: 2023/04/11 11:27:48 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				data;
	int				index_value;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		ft_lstsize(t_list *head);

void	ft_error(char *msg);
void	ft_conditions(int argc, char **argv);
int		is_stack_sorted(t_list **stack);
int		get_distance(t_list **stack, int index);
void	free_stack(t_list **stack);
void	ft_free(char **str);
//static int	ft_isnum(char *num);
//static int	ft_duplicate(int num, char **argv, int i);

void	radix_sort(t_list **stack_a, t_list **stack_b);
void	ft_index_stack(t_list **stack);
void	sort_2_args(t_list **stack_a);
void	sorting(t_list **stack_a, t_list **stack_b);
void	sort_3_args(t_list **stack_a);
void	sort_4_args(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack_a, t_list *head, int min, int next_min);
void	sort_5_args(t_list **stack_a, t_list **stack_b);

int		ft_swap(t_list **stack_a);
int		ft_push(t_list **stack_a, t_list **stack_b);
int		ft_rotate(t_list **stack_a);
int		ft_reverseRotate(t_list **stack_a);

int		ft_sa(t_list **stack_a);
int		ft_sb(t_list **stack_b);
int		ft_ss(t_list **stack_a, t_list **stack_b);
int		ft_pa(t_list **stack_a, t_list **stack_b);
int		ft_pb(t_list **stack_b, t_list **stack_a);
int		ft_ra(t_list **stack_a);
int		ft_rb(t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);
int		ft_rra(t_list **stack_a);
int		ft_rrb(t_list **stack_b);
int		ft_rrr(t_list **stack_a, t_list **stack_b);

#endif
