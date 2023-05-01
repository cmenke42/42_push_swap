/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_nums_to_stack_b.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:21:05 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/01 21:24:21 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_max_values_stk_a(t_vars *vars, t_stk *stk_a)
{
	vars->min_stk_a = stk_a->future_index;
	vars->max_stk_a = stk_a->next->next->future_index;
}

static bool	ft_find_number_below_median(t_vars *vars, t_stk **stk_a)
{
	long int	counter;
	t_stk		*temp;
	bool		result;

	result = false;
	counter = 0;
	temp = *stk_a;
	while (temp)
	{
		if (temp->future_index < vars->median)
		{
			result = true;
			break ;
		}
		counter++;
		temp = temp->next;
	}
	if (counter < vars->len_stk_a - counter)
		vars->amt_ra = counter;
	else
		vars->amt_rra = vars->len_stk_a - counter;
	ft_save_min_op_counter(vars);
	ft_rotate_stacks(vars, stk_a, NULL);
	return (result);
}

void	ft_push_all_to_stk_b(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	bool	search;

	search = true;
	while (vars->len_stk_a > 3)
	{
		if ((*stk_a)->future_index < vars->median)
			ft_pb(vars, stk_a, stk_b);
		else if (search == true)
		{
			ft_reset_operation_counter(vars);
			search = ft_find_number_below_median(vars, stk_a);
		}
		else
			ft_pb(vars, stk_a, stk_b);
	}
	ft_sort_three_nums_stk_a(stk_a);
	ft_get_max_values_stk_a(vars, *stk_a);
}
