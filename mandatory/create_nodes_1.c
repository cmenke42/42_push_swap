/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:04:00 by cmenke            #+#    #+#             */
/*   Updated: 2023/05/01 23:16:22 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//creates a new node with the passed content
//next is NULL
t_stk	*ft_new_node(int number)
{
	t_stk	*new;

	new = malloc(sizeof(t_stk));
	if (new == NULL)
		return (NULL);
	new->number = number;
	new->future_index = 0;
	new->next = NULL;
	return (new);
}

//adds new node at the end of chain.
//changes the next pointer from the current last one to the addres of new node.
//checks fo an empty list (NULL).
void	ft_node_add_back(t_stk **lst, t_stk *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_last_node(*lst)->next = new;
}

//with new->next we change the address for the next chain link.
//with *list we say where the chain starts.
void	ft_node_add_front(t_stk **lst, t_stk *new)
{
	new->next = *lst;
	*lst = new;
}
