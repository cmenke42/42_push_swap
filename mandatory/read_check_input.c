/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:37:20 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/02 00:25:44 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

bool	ft_add_num_to_stk_a_if_not_duplicate(t_stk **stk_a, long int num)
{
	t_stk	*temp;
	t_stk	*new;

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

static bool	ft_check_num(char *number, long int *num)
{
	int	j;

	j = 0;
	if (number[j] == '\0')
		return (false);
	if ((number[j] == '+' || number[j] == '-') && number[j + 1] != '\0')
		j++;
	while (number[j])
		if (ft_isdigit(number[j++]) == 0)
			return (false);
	*num = ft_atol(number);
	if (*num < INT_MIN || *num > INT_MAX)
		return (false);
	return (true);
}

bool	ft_put_numbers_to_stk_a(t_vars *vars, t_stk **stk_a)
{
	long int	num;
	long int	counter;

	counter = 0;
	while (vars->numbers[counter + vars->offset])
	{
		if (counter > UINT_MAX)
			return (false);
		if (ft_check_num(vars->numbers[counter + vars->offset], &num) == false)
			return (false);
		if (ft_add_num_to_stk_a_if_not_duplicate(stk_a, num) == false)
			return (false);
		counter++;
	}
	return (true);
}

//splits the input string if the list of numbers is inside of double quotes.
//'vars->offset' is the offset from where to read in the array since index 0
//could be the program name.
bool	ft_split_input(t_vars *vars, char **argv, int argc)
{
	if (argc == 2)
	{
		vars->numbers = ft_split(argv[1], ' ');
		if (!vars->numbers)
			return (false);
		vars->offset = 0;
	}
	else
	{
		vars->numbers = argv;
		vars->offset = 1;
	}
	return (true);
}
