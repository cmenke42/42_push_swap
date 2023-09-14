/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:39:39 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/03 15:43:32 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

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
	t_stk			*last_node_stk_a;
	long int		max_index_stk_a;
	long int		min_index_stk_a;
	long int		median;
	long int		amt_ra;
	long int		amt_rb;
	long int		amt_rra;
	long int		amt_rrb;
	long int		min_amt_ra;
	long int		min_amt_rb;
	long int		min_amt_rra;
	long int		min_amt_rrb;
}					t_vars;

// Folder -> operations
// push.c
void	ft_pa(t_vars *vars, t_stk **stk_a, t_stk **stk_b);
void	ft_pb(t_vars *vars, t_stk **stk_a, t_stk **stk_b);
// reverse_rotate.c
void	ft_rrr(t_stk **stk_a, t_stk **stk_b);
void	ft_rra(t_stk **stk_a, bool print);
void	ft_rrb(t_stk **stk_b, bool print);
// rotate.c
void	ft_rr(t_stk **stk_a, t_stk **stk_b);
void	ft_ra(t_stk **stk_a, bool print);
void	ft_rb(t_stk **stk_b, bool print);
// swap.c
void	ft_ss(t_stk **stk_a, t_stk **stk_b);
void	ft_sa(t_stk **stk_a, bool print);
void	ft_sb(t_stk **stk_b, bool print);
//folder -> mandatory
// assign_future_index.c
void	ft_assign_future_index_from_sorted_stk(t_vars *vars, t_stk *stk_a);
// create_and_modify_nodes.c
t_stk	*ft_new_node(int number);
void	ft_node_add_back(t_stk **lst, t_stk *new);
void	ft_node_add_front(t_stk **lst, t_stk *new);
void	ft_clear_all_nodes(t_stk **lst);
// get_info_about_list.c
t_stk	*ft_last_node(t_stk *lst);
t_stk	*ft_second_last_node(t_stk *lst);
int		ft_number_of_nodes(t_stk *lst);
// operation_counter.c
void	ft_reset_operation_counter(t_vars *vars);
void	ft_save_min_op_counter(t_vars *vars);
void	ft_set_rotate_counter_for_stack_a(t_vars *vars, long int counter);
void	ft_calc_moves(t_vars *vars, long int pos_b, long int *lowest_move_cost);
void	ft_calc_op_for_min_o_max(t_vars *vars, t_stk *stk_a);
// push_all_nums_to_stack_b.c
void	ft_push_all_to_stk_b(t_vars *vars, t_stk **stk_a, t_stk **stk_b);
//read_check_input.c
bool	ft_check_if_stk_a_is_unsorted(t_stk *stk_a);
bool	ft_put_numbers_to_stk_a(t_vars *vars, t_stk **stk_a);
bool	ft_split_input(t_vars *vars, char **argv, int argc);
// rotate_stacks.c
void	ft_rotate_stacks(t_vars *vars, t_stk **stk_a, t_stk **stk_b);
// sort_stack_a.c
void	ft_sort_three_nums_stk_a(t_stk **stk_a);
void	ft_rotate_index_one_to_top_of_stk_a(t_vars *vars, t_stk **stk_a);
void	ft_sort_from_b_to_a(t_vars *vars, t_stk **stk_a, t_stk **stk_b);

#endif