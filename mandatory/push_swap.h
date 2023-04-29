/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:39:39 by cmenke            #+#    #+#             */
/*   Updated: 2023/04/29 18:54:03 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
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
	unsigned int	new_index;
	struct s_stk	*next;
}					t_stk;

#endif