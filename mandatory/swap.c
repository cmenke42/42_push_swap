/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:04:42 by cmenke            #+#    #+#             */
/*   Updated: 2023/04/29 22:07:03 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stk **stk_a, t_stk **stk_b)
{
	ft_sa(stk_a, false);
	ft_sb(stk_b, false);
	ft_printf("ss\n");
}

void	ft_sa(t_stk **stk_a, bool print)
{
	t_stk	*first;
	t_stk	*second;

	first = *stk_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stk_a = second;
	if (print == true)
		ft_printf("sa\n");
}

void	ft_sb(t_stk **stk_b, bool print)
{
	t_stk	*first;
	t_stk	*second;

	first = *stk_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stk_b = second;
	if (print == true)
		ft_printf("sb\n");
}
