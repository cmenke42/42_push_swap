/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:39:39 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/01 21:21:39 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

# define MALLOC_ERROR -1
# define INPUT_ERROR -2
# define SUCCESS 1
# define LIST_TOO_SHORT -3
# define OPERATION_FAILED -4

typedef struct s_stk
{
	int				number;
	long int		future_index;
	struct s_stk	*next;
}					t_stk;

typedef struct s_vars
{
	char			**numbers;
	int				offset;
	long int		len_stk_a;
	long int		len_stk_b;
	long int		median;
	long int		amt_ra;
	long int		amt_rb;
	long int		amt_rra;
	long int		amt_rrb;
	long int		min_amt_ra;
	long int		min_amt_rb;
	long int		min_amt_rra;
	long int		min_amt_rrb;
	long int		max_stk_a;
	long int		min_stk_a;
}					t_vars;

//create_nodes_1
t_stk	*ft_new_node(int number);
void	ft_node_add_back(t_stk **lst, t_stk *new);
void	ft_node_add_front(t_stk **lst, t_stk *new);
//create_nodes_2
t_stk	*ft_last_node(t_stk *lst);
t_stk	*ft_second_last_node(t_stk *lst);
void	ft_clear_all_nodes(t_stk **lst);
int		ft_number_of_nodes(t_stk *lst);
//helper_functions
void	ft_print_stk_a(t_stk *stk_a, t_stk *stk_b);
void	ft_print_stk_a_future(t_stk *stk_a, t_stk *stk_b);
void	ft_print_op(char *operation);
void	ft_error_exit(int error_code);
// swap.c
void	ft_ss(t_stk **stk_a, t_stk **stk_b);
void	ft_sa(t_stk **stk_a, bool print);
void	ft_sb(t_stk **stk_b, bool print);
// push.c
void	ft_pa(t_vars *vars, t_stk **stk_a, t_stk **stk_b);
void	ft_pb(t_vars *vars, t_stk **stk_a, t_stk **stk_b);
// rotate.c
void	ft_rr(t_stk **stk_a, t_stk **stk_b);
void	ft_ra(t_stk **stk_a, bool print);
void	ft_rb(t_stk **stk_b, bool print);
// reverse_rotate.c
void	ft_rrr(t_stk **stk_a, t_stk **stk_b);
void	ft_rra(t_stk **stk_a, bool print);
void	ft_rrb(t_stk **stk_b, bool print);
//read_input.c
bool	ft_check_if_stk_a_is_unsorted(t_stk *stk_a);
bool	ft_put_numbers_to_stk_a(t_vars *vars, t_stk **stk_a);
bool	ft_split_input(t_vars *vars, char **argv, int argc);
// sort_stack_a.c
void	ft_sort_three_nums_stk_a(t_stk **stk_a);
// assign_future_index.c
void	ft_assign_future_index_from_sorted_stack(t_vars *vars, t_stk *stk_a);
// rotate_stacks.c
void	ft_rotate_stacks(t_vars *vars, t_stk **stk_a, t_stk **stk_b);
// operation_counter.c
void	ft_reset_operation_counter(t_vars *vars);
void	ft_save_min_op_counter(t_vars *vars);
// push_all_nums_to_stack_b.c
void	ft_push_all_to_stk_b(t_vars *vars, t_stk **stk_a, t_stk **stk_b);

#endif