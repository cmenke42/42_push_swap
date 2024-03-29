/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_future_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:19:33 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/03 15:48:12 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//searches for the next number with no future index, which has the lowest
//difference to the current min_num
static t_stk	*ft_find_next_closest_num(t_stk *stk_a, long int min_num)
{
	long int	min_diff;
	long int	diff;
	t_stk		*assign_index;

	min_diff = (long int)UINT_MAX + 10;
	while (stk_a)
	{
		if (stk_a->future_index == 0)
			diff = (min_num - stk_a->number) * -1;
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

//loops through the stack to assign each node the future index which the number
//would have in the sorted stack
void	ft_assign_future_index_from_sorted_stk(t_vars *vars, t_stk *stk_a)
{
	long int	index;
	long int	min_num;
	t_stk		*assign_index;

	index = 0;
	min_num = (long int)INT_MIN - 10;
	while (index < vars->len_stk_a)
	{
		assign_index = ft_find_next_closest_num(stk_a, min_num);
		assign_index->future_index = ++index;
		min_num = assign_index->number;
	}
	vars->median = index / 2;
}
