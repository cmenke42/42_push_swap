/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:16:35 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/01 20:17:24 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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