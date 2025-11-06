/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:19:29 by mohamed           #+#    #+#             */
/*   Updated: 2025/11/05 14:02:36 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	t_list *top;
	int size;
}	t_stack;

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
char	*push_to_b(t_stack *src, t_stack *dest);
char	*push_to_a(t_stack *src, t_stack *dest);
void	three_or_less(t_stack *a);
void four_sort(t_stack *a, t_stack *b);
void five_sort(t_stack *a, t_stack *b);
int min_instack(t_stack *stack);


#endif
