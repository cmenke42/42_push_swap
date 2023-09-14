/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_about_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:04:07 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/03 15:33:22 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns the addres of the last node in the list.
//saves the addres in temp and returns it once the while ends.
t_stk	*ft_last_node(t_stk *lst)
{
	t_stk	*tmp;
	t_stk	*last;

	tmp = lst;
	last = lst;
	while (tmp != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	return (last);
}

t_stk	*ft_second_last_node(t_stk *lst)
{
	t_stk	*tmp;
	t_stk	*second_last;

	tmp = lst;
	second_last = lst;
	while (tmp->next != NULL)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	return (second_last);
}

//Counts the number of nodes in a list till next is NULL.
int	ft_number_of_nodes(t_stk *lst)
{
	t_stk	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
