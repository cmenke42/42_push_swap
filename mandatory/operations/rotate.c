/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:03:33 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/03 15:33:12 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rr(t_stk **stk_a, t_stk **stk_b)
{
	ft_ra(stk_a, false);
	ft_rb(stk_b, false);
	ft_printf("rr\n");
}

void	ft_ra(t_stk **stk_a, bool print)
{
	t_stk	*first;
	t_stk	*last;

	last = ft_last_node(*stk_a);
	first = *stk_a;
	last->next = first;
	*stk_a = first->next;
	first->next = NULL;
	if (print == true)
		ft_printf("ra\n");
}

void	ft_rb(t_stk **stk_b, bool print)
{
	t_stk	*first;
	t_stk	*last;

	last = ft_last_node(*stk_b);
	first = *stk_b;
	last->next = first;
	*stk_b = first->next;
	first->next = NULL;
	if (print == true)
		ft_printf("rb\n");
}
