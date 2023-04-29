/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:52:48 by cmenke            #+#    #+#             */
/*   Updated: 2023/04/29 22:04:21 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int exit_code)
{
	ft_putendl_fd("Error", 2);
	return (exit_code);
}

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
}

////
///read input
////
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

/////
///end read input
/////

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_stk	*stk_a;
	t_stk	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (argc < 2)
		return (ft_error(1));
	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return (ft_error(1));
	if (ft_split_input(vars, argv, argc) == false)
		return (ft_error(1));
	if (ft_put_numbers_to_stk_a(vars, &stk_a) == false)
		return (ft_error(1));
	if (ft_check_if_stk_a_is_unsorted(stk_a) == false)
		return (0);
	ft_print_stk_a(stk_a, stk_b);
	if (stk_a)
		ft_clear_all_nodes(&stk_a);
	// ft_printf("%s\n", argv[0]);
}