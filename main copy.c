/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:52:48 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/01 21:06:34 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_error(int exit_code)
{
	ft_putendl_fd("Error", 2);
	return (exit_code);
}

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

/// assigning future indexes - START


/// assigning future indexes - END



bool	ft_find_number_below_median(t_vars *vars, t_stk **stk_a)
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

void	ft_get_max_values_stk_a(t_vars *vars, t_stk *stk_a)
{
	vars->min_stk_a = stk_a->future_index;
	vars->max_stk_a = stk_a->next->next->future_index;
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
	if (vars->len_stk_a == 3)
		ft_sort_three_nums_stk_a(stk_a);
	ft_get_max_values_stk_a(vars, *stk_a);
}

void	ft_calc_op_for_min_o_max(t_vars *vars, t_stk **stk_a)
{
	long int	counter;
	t_stk		*temp;

	counter = 0;
	temp = *stk_a;
	while (temp->future_index != vars->min_stk_a)
	{
		counter++;
		temp = temp->next;
	}
	if (counter < vars->len_stk_a - counter)
		vars->amt_ra = counter;
	else
		vars->amt_rra = vars->len_stk_a - counter;
}

void	ft_find_spot_in_a(t_vars *vars, t_stk *stk_a, long int index, t_stk **_a)
{
	long int	counter;

	counter = 0;
	if (index < vars->min_stk_a || index > vars->max_stk_a)
		ft_calc_op_for_min_o_max(vars, _a);
	else if (index < stk_a->future_index && index > ft_last_node(stk_a)->future_index)
		return ;
	else
	{
		while (stk_a->next)
		{	
			counter++;
			if (index > stk_a->future_index && index < stk_a->next->future_index)
				break;
			stk_a = stk_a->next;
		}
		if (counter < vars->len_stk_a - counter)
			vars->amt_ra = counter;
		else
			vars->amt_rra = vars->len_stk_a - counter;
	}
}

long int	ft_calc_movement_cost(t_vars *vars, long int pos_in_b)
{
	long int	total;

	ft_reset_operation_counter(vars);
	if (pos_in_b < vars->len_stk_b - pos_in_b)
		vars->amt_rb = pos_in_b;
	else if (pos_in_b != 0)
		vars->amt_rrb = vars->len_stk_b - pos_in_b;
	total = vars->amt_ra + vars->amt_rb + vars->amt_rra + vars->amt_rrb;
	return (total);
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
	if (counter < vars->len_stk_a - counter)
		vars->amt_ra = counter;
	else
		vars->amt_rra = vars->len_stk_a - counter;
	ft_save_min_op_counter(vars);
	ft_rotate_stacks(vars, stk_a, NULL);
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
		lowest_move_cost = UINT_MAX + 10;
		while (temp_b)
		{
			ft_find_spot_in_a(vars, *stk_a, temp_b->future_index, stk_a);
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

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_stk	*stk_a;
	t_stk	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (argc < 2)
		return (0);
	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return (ft_error(1));
	if (ft_split_input(vars, argv, argc) == false)
		return (ft_error(1));
	///make sure to free tha allocated array and struct before quitting the prgoram
	if (ft_put_numbers_to_stk_a(vars, &stk_a) == false)
		return (ft_error(1));
	if (ft_check_if_stk_a_is_unsorted(stk_a) == false)
		return (0);
	vars->len_stk_a = ft_number_of_nodes(stk_a);
	if (vars->len_stk_a == 2)
		ft_sa(&stk_a, true);
	else if (vars->len_stk_a == 3)
		ft_sort_three_nums_stk_a(&stk_a);
	else
	{
		ft_assign_future_index_from_sorted_stack(vars, stk_a);
		ft_push_all_to_stk_b(vars, &stk_a, &stk_b);
		ft_sort_from_b_to_a(vars, &stk_a, &stk_b);
		ft_rotate_index_one_to_top_of_stk_a(vars, &stk_a);
	}
	ft_print_stk_a_future(stk_a, stk_b);
	//make sure to free the nodes if a fial happens during allocation of the nodes
	if (argc == 2)
		free(vars->numbers);
	ft_clear_all_nodes(&stk_a);
	free(vars);
	return (0);
}
