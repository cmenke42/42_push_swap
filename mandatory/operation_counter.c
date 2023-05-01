/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:13:25 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/01 23:12:08 by cmenke           ###   ########.fr       */
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

long int	ft_calc_movement_cost(t_vars *vars, long int pos_in_b)
{
	long int	total;

	if (pos_in_b < vars->len_stk_b - pos_in_b)
		vars->amt_rb = pos_in_b;
	else if (pos_in_b != 0)
		vars->amt_rrb = vars->len_stk_b - pos_in_b;
	total = vars->amt_ra + vars->amt_rb + vars->amt_rra + vars->amt_rrb;
	return (total);
}

void	ft_calc_op_for_min_o_max(t_vars *vars, t_stk *stk_a)
{
	long int	counter;

	counter = 0;
	while (stk_a->future_index != vars->min_stk_a)
	{
		counter++;
		stk_a = stk_a->next;
	}
	ft_set_rotate_counter_for_stack_a(vars, counter);
}
