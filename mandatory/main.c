/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:52:48 by cmenke            #+#    #+#             */
/*   Updated: 2023/04/30 21:22:07 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//delete
#include <stdio.h>





#include "push_swap.h"


int	ft_error(int exit_code)
{
	ft_putendl_fd("Error", 2);
	return (exit_code);
}

//////
/// check and parse the input -- START
///////
bool	ft_check_if_stk_a_is_unsorted(t_stk *stk_a)
{
	while (stk_a && stk_a->next)
	{
		if (stk_a->number > stk_a->next->number)
			return (true);
		stk_a = stk_a->next;
	}
	return (false);
}

bool	ft_check_num(char *number, long int *num)
{
	int			j;

	j = 0;
	if (number[j] == '+' || number[j] == '-')
		j++;
	while (number[j])
		if (ft_isdigit(number[j++]) == 0)
			return (false);
	*num = ft_atol(number);
	if (*num < INT_MIN || *num > INT_MAX)
		return (false);
	return (true);
}

bool	ft_add_num_to_stk_a_if_not_duplicate(t_stk **stk_a, long int num)
{
	t_stk *temp;
	t_stk *new;

	temp = *stk_a;
	if (temp)
	{
		while (temp->next)
		{
			if (num == temp->number)
				return (false);
			temp = temp->next;
		}
		if (num == temp->number)
			return (false);
	}
	new = ft_new_node((int)num);
	if (!new)
		return (false);
	if (temp)
		temp->next = new;
	else
		*stk_a = new;
	return (true);
}

bool	ft_put_numbers_to_stk_a(t_vars *vars, t_stk **stk_a)
{
	long int	num;

	while (vars->numbers[vars->start_pos])
	{
		if (ft_check_num(vars->numbers[vars->start_pos], &num) == false)
			return (false);
		if (ft_add_num_to_stk_a_if_not_duplicate(stk_a, num) == false)
			return (false);
		vars->start_pos++;
	}
	return (true);
}

bool	ft_split_input(t_vars *vars, char **argv, int argc)
{
	if (argc == 2)
	{
		vars->numbers = ft_split(argv[1], ' ');
		if (!vars->numbers)
			return (false);
		vars->start_pos = 0;
	}
	else
	{
		vars->numbers = argv;
		vars->start_pos = 1;
	}
	return (true);
}

//////
/// check and parse the input -- END
///////

//////
/// sorting the numbers - START
///////

/// 3 numbers in stack a - START

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

///3 numbers in stack a - END

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
void	ft_calc_first_diff(int min_num, t_stk *stk_a, long int *min_diff)
{
	while (stk_a)
	{
		if (stk_a->future_index == 0)
			*min_diff = ((long int)min_num - stk_a->number) * -1;
		stk_a = stk_a->next;
	}	
}

t_stk	*ft_find_next_closest_num(t_stk *stk_a, long int min_diff, int min_num)
{
	long int		diff;
	t_stk			*assign_index;

	while (stk_a)
	{
		if (stk_a->future_index == 0)
			diff = ((long int)min_num - stk_a->number) * -1;
		if (stk_a->future_index == 0 && diff <= min_diff)
		{
			min_diff = diff;
			assign_index = stk_a;
		}
		stk_a = stk_a->next;
	}
	return (assign_index);
}

void	ft_assign_future_index(t_vars *vars, t_stk *stk_a)
{
	unsigned int	index;
	int				min_num;
	long int		min_diff;
	t_stk			*assign_index;
	
	index = 0;
	min_num = INT_MIN;
	while (index < vars->len_stk_a)
	{
		ft_calc_first_diff(min_num, stk_a, &min_diff);
		assign_index = ft_find_next_closest_num(stk_a, min_diff, min_num);
		assign_index->future_index = ++index;
		min_num = assign_index->number;
	}
	vars->median = index / 2;
}

/// assigning future indexes - END

void	ft_do_rotate_op(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	while (vars->min_amt_ra || vars->min_amt_rb)
	{
		if (vars->min_amt_ra && vars->min_amt_rb)
		{
			ft_rr(stk_a, stk_b);
			vars->min_amt_ra--;
			vars->min_amt_rb--;
		}
		else if (vars->min_amt_ra)
		{
			ft_ra(stk_a, true);
			vars->min_amt_ra--;
		}
		else if (vars->min_amt_rb)
		{
			ft_rb(stk_b, true);
			vars->min_amt_rb--;
		}
	}
}

void	ft_do_reverse_rotate_op(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	while (vars->min_amt_rra || vars->min_amt_rrb)
	{
		if (vars->min_amt_rra && vars->min_amt_rrb)
		{
			ft_rrr(stk_a, stk_b);
			vars->min_amt_rra--;
			vars->min_amt_rrb--;
		}
		else if (vars->min_amt_rra)
		{
			ft_rra(stk_a, true);
			vars->min_amt_rra--;
		}
		else if (vars->min_amt_rrb)
		{
			ft_rrb(stk_b, true);
			vars->min_amt_rrb--;
		}
	}
}

bool	ft_find_number_below_median(t_vars *vars, t_stk **stk_a)
{
	unsigned int	counter;
	t_stk			*temp;
	bool			result;

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
	ft_do_rotate_op(vars, stk_a, NULL);
	ft_do_reverse_rotate_op(vars, stk_a, NULL);
	return (result);
}

// bool	ft_find_number_below_median(t_vars *vars, t_stk **stk_a)
// {
// 	t_stk	*temp;
// 	bool	result;

// 	temp = *stk_a;
// 	result = false;
// 	while (temp)
// 	{
// 		if (temp->future_index < vars->median)
// 		{
// 			result = true;
// 			break ;
// 		}
// 		temp = temp->next;
// 	}
// 	while (result == true && temp->future_index != (*stk_a)->future_index)
// 		ft_ra(stk_a, true);
// 	return (result);
// }

void	ft_get_max_values_stk_a(t_vars *vars, t_stk *stk_a)
{
	vars->min_stk_a = stk_a->future_index;
	vars->max_stk_a = stk_a->next->next->future_index;
}

//optimize with the direction of turning ra or rra - maybe??
void	ft_push_all_to_stk_b(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	bool			search;

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
	unsigned int	counter;
	t_stk			*temp;

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

void	ft_find_spot_in_a(t_vars *vars, t_stk *stk_a, unsigned int index, t_stk **_a)
{
	unsigned int	counter;

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
// long int	ft_calc_movement_cost(t_vars *vars)
// {
// 	unsigned int	amt_ra;
// 	unsigned int	amt_rb;
// 	unsigned int	amt_rra;
// 	unsigned int	amt_rrb;

// 	if (vars->amt_ra > vars->amt_rb)
// 		sum_one = vars->amt_ra;
// 	else 
// 		sum_one = vars->amt_rb;
// 	if (vars->amt_rra > vars->amt_rrb)
// 		sum_two = vars->amt_rra;
// 	else 
// 		sum_two = vars->amt_rrb;
// 	if (vars->amt_ra < vars->amt_rb)
// 	{
// 		if (vars->amt_rra < vars->amt_rrb)
// 			sum_three = vars->amt_ra + vars->amt_rra;
// 		if (vars->amt_rrb < vars->amt_rra)
// 			sum_three = vars->amt_ra + vars->amt_rrb;
// 	}
// 	else if (vars->amt_rb < vars->amt_ra)
// 	{
// 		if (vars->amt_rra < vars->amt_rrb)
// 			sum_three = vars->amt_rb + vars->amt_rra;
// 		if (vars->amt_rrb < vars->amt_rra)
// 			sum_three = vars->amt_rb + vars->amt_rrb;
// 	}

// }

long int	ft_calc_movement_cost(t_vars *vars, unsigned int pos_in_b)
{
	long int	total;

	if (pos_in_b < vars->len_stk_b - pos_in_b)
		vars->amt_rb = pos_in_b;
	else if (pos_in_b != 0)
		vars->amt_rrb = vars->len_stk_b - pos_in_b;
	total = vars->amt_ra + vars->amt_rb + vars->amt_rra + vars->amt_rrb;
	return (total);
}

void	ft_finish_up_stk_a(t_vars *vars, t_stk **stk_a)
{
	unsigned int	counter;
	t_stk			*temp;

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
	while(vars->amt_ra)
	{
		ft_ra(stk_a, true);
		vars->amt_ra--;
	}
	while(vars->amt_rra)
	{
		ft_rra(stk_a, true);
		vars->amt_rra--;
	}
}

void	ft_sort_from_b_to_a(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	long int		move_cost;
	long int		lowest_move_cost;
	unsigned int	pos_in_b;
	t_stk			*temp_b;

	while (vars->len_stk_b > 0)
	{
		// ft_print_stk_a_future(*stk_a, *stk_b);
		temp_b = *stk_b;
		pos_in_b = 0;
		ft_find_spot_in_a(vars, *stk_a, temp_b->future_index, stk_a);
		lowest_move_cost = ft_calc_movement_cost(vars, pos_in_b);
		ft_save_min_op_counter(vars);
		while (temp_b)
		{
			ft_reset_operation_counter(vars);
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
		ft_do_reverse_rotate_op(vars, stk_a, stk_b);
		ft_do_rotate_op(vars, stk_a, stk_b);
		ft_pa(vars, stk_a, stk_b);
	}
	///check wich one is cheaper
	// while ((*stk_a)->future_index != 1)
	// 	ft_ra(stk_a, true);
	ft_finish_up_stk_a(vars, stk_a);
}
// void	ft_sort_from_b_to_a(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
// {
// 	unsigned int	counter;
// 	t_stk			*temp_b;

// 	while (vars->len_stk_b > 0)
// 	{
// 		temp_b = *stk_b;
// 		// counter = 0;
// 		// ft_find_spot_in_a(vars, *stk_a, temp_b->future_index);
// 		// ft_save_min_op_counter(vars);
// 		while (temp_b)
// 		{	
// 			ft_find_spot_in_a(vars, *stk_a, temp_b->future_index, stk_a);
// 			// if (counter < vars->len_stk_b - counter)
// 			// 	vars->amt_rb = counter;
// 			// else 
// 			// 	vars->amt_rrb = vars->len_stk_b - counter;
// 			// if (vars->amt_ra + vars->amt_rb + vars->amt_rra + vars->amt_rrb < vars->min_amt_ra + vars->min_amt_rb + vars->min_amt_rra + vars->min_amt_rrb)
// 			// 	ft_save_min_op_counter(vars);
// 			// ft_reset_operation_counter(vars);
// 			// counter++;
// 			temp_b = temp_b->next;
// 			ft_print_stk_a_future(*stk_a, *stk_b);
// 			ft_pa(vars, stk_a, stk_b);
// 		}
// 		// ft_do_reverse_rotate_op(vars, stk_a, stk_b);
// 		// ft_do_rotate_op(vars, stk_a, stk_b);
// 		// ft_pa(vars, stk_a, stk_b);
// 	}
// }

//////
/// sorting the numbers -- END
///////


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
	if (ft_put_numbers_to_stk_a(vars, &stk_a) == false)
		return (ft_error(1));
	if (ft_check_if_stk_a_is_unsorted(stk_a) == false)
		return (0);
	vars->len_stk_a = ft_number_of_nodes(stk_a);
	if (vars->len_stk_a == 2)
		ft_sa(&stk_a, true);
	if (vars->len_stk_a == 3)
		ft_sort_three_nums_stk_a(&stk_a);
	ft_assign_future_index(vars, stk_a);
	////sorting of there are more than 3 numbers
	// ft_print_stk_a_future(stk_a, stk_b);
	ft_push_all_to_stk_b(vars, &stk_a, &stk_b);
	// ft_print_stk_a_future(stk_a, stk_b);
	ft_sort_from_b_to_a(vars, &stk_a, &stk_b);
	// ft_print_stk_a_future(stk_a, stk_b);

	//make sure to free the nodes if a fial happens during allocation of the nodes
	if (stk_a)
		ft_clear_all_nodes(&stk_a);
	return (0);
}
