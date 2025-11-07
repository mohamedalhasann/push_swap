/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myrules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:13:29 by mohamed           #+#    #+#             */
/*   Updated: 2025/11/07 23:41:10 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack *stack)
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
	
}
char	*push_to_b(t_stack *src, t_stack *dest)
{
	t_list	*node;

	if (!src || !src->top)
		return NULL;
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
		return NULL;
	node = src->top;
	src->top = src->top->next;
	node->next = NULL;
	ft_lstadd_front(&dest->top, node);
	dest->size++;
	src->size--;
	return ("pa\n");
}
void	rotate(t_stack *stack)
{
	t_list	*first;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	stack->top = stack->top->next;
	first->next = NULL;
	ft_lstadd_back(&stack->top, first);
}
void	reverse_rotate(t_stack *stack)
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
}
