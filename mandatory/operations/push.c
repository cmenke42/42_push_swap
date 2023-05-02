/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:03:45 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/02 21:01:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*first;

	if ((*stk_b)->future_index > vars->max_index_stk_a)
		vars->max_index_stk_a = (*stk_b)->future_index;
	else if ((*stk_b)->future_index < vars->min_index_stk_a)
		vars->min_index_stk_a = (*stk_b)->future_index;
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
