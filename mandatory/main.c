/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:52:48 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/01 23:16:12 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int exit_code)
{
	if (exit_code != 0)
		ft_putendl_fd("Error", 2);
	return (exit_code);
}

bool	ft_create_and_check_stack_a(t_vars *vars, t_stk **stk_a)
{
	long int	counter;
	bool		result;

	counter = 0;
	result = ft_put_numbers_to_stk_a(vars, stk_a);
	if (result == false)
		ft_clear_all_nodes(stk_a);
	if (vars->offset == 0)
	{
		while (vars->numbers[counter + vars->offset])
			free(vars->numbers[counter++ + vars->offset]);
		free(vars->numbers);
	}
	return (result);
}

void	ft_sort_the_numbers(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	vars->len_stk_a = ft_number_of_nodes(*stk_a);
	if (vars->len_stk_a == 2)
		ft_sa(stk_a, true);
	else if (vars->len_stk_a == 3)
		ft_sort_three_nums_stk_a(stk_a);
	else
	{
		ft_assign_future_index_from_sorted_stk(vars, *stk_a);
		ft_push_all_to_stk_b(vars, stk_a, stk_b);
		ft_sort_from_b_to_a(vars, stk_a, stk_b);
		ft_rotate_index_one_to_top_of_stk_a(vars, stk_a);
	}
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_stk	*stk_a;
	t_stk	*stk_b;
	int		exit_code;

	stk_a = NULL;
	stk_b = NULL;
	exit_code = 0;
	if (argc < 2)
		return (0);
	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return (ft_error(1));
	if (ft_split_input(vars, argv, argc) == false)
		exit_code = 1;
	if (exit_code == 0 && ft_create_and_check_stack_a(vars, &stk_a) == false)
		exit_code = 1;
	if (exit_code == 0 && ft_check_if_stk_a_is_unsorted(stk_a) == false)
		exit_code = 0;
	else if (exit_code == 0)
		ft_sort_the_numbers(vars, &stk_a, &stk_b);
	ft_clear_all_nodes(&stk_a);
	free(vars);
	return (ft_error(exit_code));
}
