/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:39:39 by cmenke            #+#    #+#             */
/*   Updated: 2023/04/29 21:59:33 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

# define MALLOC_ERROR -1
# define INPUT_ERROR -2
# define SUCCESS 1
# define LIST_TOO_SHORT -3
# define OPERATION_FAILED -4

typedef struct s_stk
{
	int				number;
	struct s_stk	*next;
}					t_stk;

typedef struct s_vars
{
	char		**numbers;
	long int	start_pos;
	long int	len_stk_a;
	long int	len_stk_b;
}					t_vars;

//create_nodes_1
t_stk	*ft_new_node(int number);
void	ft_node_add_back(t_stk **lst, t_stk *new);
void	ft_node_add_front(t_stk **lst, t_stk *new);
//create_nodes_2
t_stk	*ft_last_node(t_stk *lst);
t_stk	*ft_second_last_node(t_stk *lst);
void	ft_clear_all_nodes(t_stk **lst);
int		ft_number_of_nodes(t_stk *lst);
//helper_functions
void	ft_print_stk_a(t_stk *stk_a, t_stk *stk_b);
void	ft_print_op(char *operation);
void	ft_error_exit(int error_code);

#endif