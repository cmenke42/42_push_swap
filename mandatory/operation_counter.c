/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:13:25 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/03 15:33:26 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_operation_counter(t_vars *vars)
{
	vars->amt_ra = 0;
	vars->amt_rb = 0;
	vars->amt_rra = 0;
	vars->amt_rrb = 0;
}

void	ft_save_min_op_counter(t_vars *vars)
{
	vars->min_amt_ra = vars->amt_ra;
	vars->min_amt_rb = vars->amt_rb;
	vars->min_amt_rra = vars->amt_rra;
	vars->min_amt_rrb = vars->amt_rrb;
}

void	ft_set_rotate_counter_for_stack_a(t_vars *vars, long int counter)
{
	if (counter < vars->len_stk_a - counter)
		vars->amt_ra = counter;
	else
		vars->amt_rra = vars->len_stk_a - counter;
}

void	ft_calc_moves(t_vars *vars, long int pos_b, long int *lowest_move_cost)
{
	long int	move_cost;

	if (pos_b < vars->len_stk_b - pos_b)
		vars->amt_rb = pos_b;
	else if (pos_b != 0)
		vars->amt_rrb = vars->len_stk_b - pos_b;
	move_cost = vars->amt_ra + vars->amt_rb + vars->amt_rra + vars->amt_rrb;
	if (move_cost < *lowest_move_cost)
	{
		ft_save_min_op_counter(vars);
		*lowest_move_cost = move_cost;
	}
}

void	ft_calc_op_for_min_o_max(t_vars *vars, t_stk *stk_a)
{
	long int	counter;

	counter = 0;
	while (stk_a->future_index != vars->min_index_stk_a)
	{
		counter++;
		stk_a = stk_a->next;
	}
	ft_set_rotate_counter_for_stack_a(vars, counter);
}
