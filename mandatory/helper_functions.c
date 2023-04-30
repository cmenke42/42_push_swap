/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:04:12 by cmenke            #+#    #+#             */
/*   Updated: 2023/04/30 01:15:12 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_print_stk_a(t_stk *stk_a, t_stk *stk_b)
{
	t_stk	*last_a;
	t_stk	*last_b;

	last_a = stk_a;
	last_b = stk_b;
	while (stk_a != NULL || stk_b != NULL)
	{
		if (stk_a != NULL)
		{
			ft_printf("num:%d, fut:%d", stk_a->number, stk_a->future_index);
			stk_a = stk_a->next;
		}
		else
			ft_printf("#");
		if (stk_b != NULL)
		{
			ft_printf(" -- %d", stk_b->number);
			stk_b = stk_b->next;
		}
		else
			ft_printf(" -- #");
		ft_printf("\n");
	}
}

void	ft_print_stk_a_future(t_stk *stk_a, t_stk *stk_b)
{
	t_stk	*last_a;
	t_stk	*last_b;

	last_a = stk_a;
	last_b = stk_b;
	while (stk_a != NULL || stk_b != NULL)
	{
		if (stk_a != NULL)
		{
			ft_printf("%d", stk_a->future_index);
			stk_a = stk_a->next;
		}
		else
			ft_printf("#");
		if (stk_b != NULL)
		{
			ft_printf(" -- %d", stk_b->future_index);
			stk_b = stk_b->next;
		}
		else
			ft_printf(" -- #");
		ft_printf("\n");
	}
}

void	ft_print_op(char *operation)
{
	static int	counter;

	counter++;
	ft_printf("%s counter:%d\n", operation, counter);
}

void	ft_error_exit(int error_code)
{
	error_code = 1;
	ft_putendl_fd("Error\n", 2);
	exit(error_code);
}
