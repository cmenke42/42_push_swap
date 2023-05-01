/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_future_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:19:33 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/01 20:48:15 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stk	*ft_find_next_closest_num(t_stk *stk_a, int min_num)
{
	long int	min_diff;
	long int	diff;
	t_stk		*assign_index;

	min_diff = (long int)UINT_MAX + 10;
	while (stk_a)
	{
		if (stk_a->future_index == 0)
			diff = ((long int)min_num - stk_a->number) * -1;
		if (stk_a->future_index == 0 && diff <= min_diff)
		{
			min_diff = diff;
			assign_index = stk_a;
			if (min_diff == 1)
				return (assign_index);
		}
		stk_a = stk_a->next;
	}
	return (assign_index);
}

void	ft_assign_future_index_from_sorted_stack(t_vars *vars, t_stk *stk_a)
{
	long int	index;
	int			min_num;
	t_stk		*assign_index;

	index = 0;
	min_num = INT_MIN;
	while (index < vars->len_stk_a)
	{
		assign_index = ft_find_next_closest_num(stk_a, min_num);
		assign_index->future_index = ++index;
		min_num = assign_index->number;
	}
	vars->median = index / 2;
}