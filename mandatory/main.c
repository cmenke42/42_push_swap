/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:52:48 by cmenke            #+#    #+#             */
/*   Updated: 2023/04/29 20:06:54 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int exit_code)
{
	ft_putendl_fd("Error", 2);
	return (exit_code);
}

bool	ft_check_num(char **numbers, int i, long int *num)
{
	int			j;

	j == 0;
	if (numbers[i])
	{
		if (numbers[i][j] == '+' || numbers[i][j] == '-')
			j++;
		while (numbers[i][j])
			if (ft_isdigit(numbers[i][j++] - '0' == 0))
				return (false);
		*num = ft_atol(numbers[i]);
		if (*num < INT_MIN || *num > INT_MAX)
			return (false);
	}
	return (true);
}

////
///read input
////
bool	ft_read_input(t_vars *vars, char **argv, int argc)
{
	char		**numbers;
	int			start_pos;
	long int	num;

	start_pos = 0;
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			return (false);
		start_pos = 1;
	}
	else
		numbers = argv;
	return (true);
}

/////
///end read input
/////

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc < 2)
		return (ft_error(1));
	// ft_printf("%s\n", argv[0]);
}