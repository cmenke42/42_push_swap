/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:36:49 by cmenke            #+#    #+#             */
/*   Updated: 2023/03/12 20:27:05 by cmenke           ###   ########.fr       */
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

//deletes content, frees the node and sets the start pointer (*lst) to NULL.
//repeats for complete chain of nodes.
//checks if del is not NULL.
void	ft_clear_all_nodes(t_stk **lst)
{
	t_stk	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		*lst = tmp;
		tmp = tmp->next;
		free(*lst);
	}
	*lst = NULL;
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
