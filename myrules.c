/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myrules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:13:29 by mohamed           #+#    #+#             */
/*   Updated: 2025/11/12 11:16:54 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_to_b(t_stack *src, t_stack *dest)
{
	t_list	*node;

	if (!src || !src->top)
		return (NULL);
	node = src->top;
	src->top = src->top->next;
	node->next = NULL;
	ft_lstadd_front(&dest->top, node);
	dest->size++;
	src->size--;
	return ("pb\n");
}

char	*push_to_a(t_stack *src, t_stack *dest)
{
	t_list	*node;

	if (!src || !src->top)
		return (NULL);
	node = src->top;
	src->top = src->top->next;
	node->next = NULL;
	ft_lstadd_front(&dest->top, node);
	dest->size++;
	src->size--;
	return ("pa\n");
}

void	swap(t_stack *stack, char c)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_stack *stack, char c)
{
	t_list	*first;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	stack->top = stack->top->next;
	first->next = NULL;
	ft_lstadd_back(&stack->top, first);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack *stack, char c)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	prev = stack->top;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	ft_lstadd_front(&stack->top, last);
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
