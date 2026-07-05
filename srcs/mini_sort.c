/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:33:35 by malhassa          #+#    #+#             */
/*   Updated: 2025/11/15 14:16:20 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_instack(t_stack *stack)
{
	t_list	*node;
	int		min;

	node = stack->top;
	min = node->content;
	while (node)
	{
		if (node->content < min)
			min = node->content;
		node = node->next;
	}
	return (min);
}

void	three_or_less(t_stack *a)
{
	if (issorted(stacktoarray(a, a->size), a->size))
		return ;
	if (a->top->content == min_instack(a))
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (a->top->content == max_instack(a))
	{
		rotate(a, 'a');
		if (a->top->content > a->top->next->content)
			swap(a, 'a');
	}
	else
	{
		if (a->top->content > a->top->next->content)
			swap(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
}

void	four_sort(t_stack *a, t_stack *b)
{
	while (a->top->content != min_instack(a))
		rotate(a, 'a');
	write(1, push_to_b(a, b), 3);
	three_or_less(a);
	write(1, push_to_a(b, a), 3);
}

void	five_sort(t_stack *a, t_stack *b)
{
	while (a->top->content != min_instack(a))
		rotate(a, 'a');
	write(1, push_to_b(a, b), 3);
	while (a->top->content != min_instack(a))
		reverse_rotate(a, 'a');
	write(1, push_to_b(a, b), 3);
	three_or_less(a);
	write(1, push_to_a(b, a), 3);
	write(1, push_to_a(b, a), 3);
}

void	minisort(t_stack *a, t_stack *b)
{
	if (a->size == 5)
		five_sort(a, b);
	else if (a->size == 4)
		four_sort(a, b);
	else if (a->size <= 3)
		three_or_less(a);
}
