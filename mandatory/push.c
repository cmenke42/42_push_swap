/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:03:45 by cmenke            #+#    #+#             */
/*   Updated: 2023/04/29 22:08:25 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*first;

	first = (*stk_b)->next;
	ft_node_add_front(stk_a, *stk_b);
	*stk_b = first;
	vars->len_stk_a++;
	vars->len_stk_b--;
	ft_printf("pa\n");
}

void	ft_pb(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*first;

	first = (*stk_a)->next;
	ft_node_add_front(stk_b, *stk_a);
	*stk_a = first;
	vars->len_stk_a--;
	vars->len_stk_b++;
	ft_printf("pb\n");
}
