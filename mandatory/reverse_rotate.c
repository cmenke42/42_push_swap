/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:03:39 by cmenke            #+#    #+#             */
/*   Updated: 2023/04/29 22:07:50 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stk **stk_a, t_stk **stk_b)
{
	ft_rra(stk_a, false);
	ft_rrb(stk_b, false);
	ft_printf("rrr\n");
}

void	ft_rra(t_stk **stk_a, bool print)
{
	t_stk	*first;
	t_stk	*last;
	t_stk	*second_last;

	second_last = ft_second_last_node(*stk_a);
	last = second_last->next;
	first = *stk_a;
	last->next = first;
	second_last->next = NULL;
	*stk_a = last;
	if (print == true)
		ft_printf("rra\n");
}

void	ft_rrb(t_stk **stk_b, bool print)
{
	t_stk	*first;
	t_stk	*last;
	t_stk	*second_last;

	second_last = ft_second_last_node(*stk_b);
	last = second_last->next;
	first = *stk_b;
	last->next = first;
	second_last->next = NULL;
	*stk_b = last;
	if (print == true)
		ft_printf("rrb\n");
}


