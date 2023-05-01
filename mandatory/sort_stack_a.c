/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:16:35 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/01 23:15:33 by cmenke           ###   ########.fr       */
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
	t_stk		*start_stk_a;

	counter = 0;
	start_stk_a = stk_a;
	ft_reset_operation_counter(vars);
	if (index < vars->min_stk_a || index > vars->max_stk_a)
		ft_calc_op_for_min_o_max(vars, start_stk_a);
	else if (index < stk_a->future_index
		&& index > ft_last_node(stk_a)->future_index)
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
	long int	move_cost;
	long int	lowest_move_cost;
	long int	pos_in_b;
	t_stk		*temp_b;

	while (vars->len_stk_b > 0)
	{
		temp_b = *stk_b;
		pos_in_b = 0;
		lowest_move_cost = (long int)UINT_MAX + 10;
		while (temp_b)
		{
			ft_find_spot_in_a(vars, *stk_a, temp_b->future_index);
			move_cost = ft_calc_movement_cost(vars, pos_in_b);
			if (move_cost < lowest_move_cost)
			{
				ft_save_min_op_counter(vars);
				lowest_move_cost = move_cost;
			}
			pos_in_b++;
			temp_b = temp_b->next;
		}
		ft_rotate_stacks(vars, stk_a, stk_b);
		ft_pa(vars, stk_a, stk_b);
	}
}
