/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:06:25 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/01 21:07:15 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_do_rotate_op(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	while (vars->min_amt_ra || vars->min_amt_rb)
	{
		if (vars->min_amt_ra && vars->min_amt_rb)
		{
			ft_rr(stk_a, stk_b);
			vars->min_amt_ra--;
			vars->min_amt_rb--;
		}
		else if (vars->min_amt_ra)
		{
			ft_ra(stk_a, true);
			vars->min_amt_ra--;
		}
		else if (vars->min_amt_rb)
		{
			ft_rb(stk_b, true);
			vars->min_amt_rb--;
		}
	}
}

static void	ft_do_reverse_rotate_op(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	while (vars->min_amt_rra || vars->min_amt_rrb)
	{
		if (vars->min_amt_rra && vars->min_amt_rrb)
		{
			ft_rrr(stk_a, stk_b);
			vars->min_amt_rra--;
			vars->min_amt_rrb--;
		}
		else if (vars->min_amt_rra)
		{
			ft_rra(stk_a, true);
			vars->min_amt_rra--;
		}
		else if (vars->min_amt_rrb)
		{
			ft_rrb(stk_b, true);
			vars->min_amt_rrb--;
		}
	}
}

void	ft_rotate_stacks(t_vars *vars, t_stk **stk_a, t_stk **stk_b)
{
	ft_do_rotate_op(vars, stk_a, stk_b);
	ft_do_reverse_rotate_op(vars, stk_a, stk_b);
}
