/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:16:35 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/02 21:18:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_nums_stk_a(t_stk **stk_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stk_a)->number;
	second = (*stk_a)->next->number;
	third = (*stk_a)->next->next->number;
	if (first > second && first > third)
		ft_ra(stk_a, true);
	else if (first < second && second > third)
		ft_rra(stk_a, true);
	if ((*stk_a)->number > (*stk_a)->next->number)
		ft_sa(stk_a, true);
}

void	ft_rotate_index_one_to_top_of_stk_a(t_vars *vars, t_stk **stk_a)
{
	long int	counter;
	t_stk		*temp;

	counter = 0;
	temp = *stk_a;
	ft_reset_operation_counter(vars);
	while (temp->future_index != 1)
	{
		counter++;
		temp = temp->next;
	}
	ft_set_rotate_counter_for_stack_a(vars, counter);
	ft_save_min_op_counter(vars);
	ft_rotate_stacks(vars, stk_a, NULL);
}

static void	ft_find_spot_in_a(t_vars *vars, t_stk *stk_a, long int index)
{
	long int	counter;

	counter = 0;
	ft_reset_operation_counter(vars);
	if (index < vars->min_index_stk_a || index > vars->max_index_stk_a)
		ft_calc_op_for_min_o_max(vars, stk_a);
	else if (index < stk_a->future_index
		&& index > vars->last_node_stk_a->future_index)
		return ;
	else
	{
		while (stk_a->next)
		{	
			counter++;
			if (index > stk_a->future_index
				&& index < stk_a->next->future_index)
				break ;
			stk_a = stk_a->next;
		}
		ft_set_rotate_counter_for_stack_a(vars, counter);
	}
}

void	ft_sort_from_b_to_a(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	long int	lowest_move_cost;
	long int	pos_in_b;
	t_stk		*temp_b;

	while (vars->len_stk_b > 0)
	{
		temp_b = *stk_b;
		pos_in_b = 0;
		lowest_move_cost = (long int)UINT_MAX + 10;
		vars->last_node_stk_a = ft_last_node(*stk_a);
		while (temp_b)
		{
			ft_find_spot_in_a(vars, *stk_a, temp_b->future_index);
			ft_calc_moves(vars, pos_in_b, &lowest_move_cost);
			if (lowest_move_cost == 1)
				break ;
			pos_in_b++;
			temp_b = temp_b->next;
		}
		ft_rotate_stacks(vars, stk_a, stk_b);
		ft_pa(vars, stk_a, stk_b);
	}
}
