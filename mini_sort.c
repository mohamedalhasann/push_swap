/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:51:04 by malhassa          #+#    #+#             */
/*   Updated: 2025/11/04 22:34:05 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int max_instack(t_stack *stack)
{
    t_list *node;
    int max;

    node = stack->top;
    max = *(int *)node->content;
    while (node)
    {
        if(*(int *)node->content > max)
            max = *(int *)node->content;
        node = node->next;
    }
    return (max);   
}
int min_instack(t_stack *stack)
{
    t_list  *node;
    int     min;

    if (!stack || stack->size == 0)
        return (0);

    node = stack->top;
    min = *(int *)node->content;

    while (node)
    {
        if (*(int *)node->content < min)
            min = *(int *)node->content;
        node = node->next;
    }
    return (min);
}
int isSorted(int *arr, int size)
{
    int i;

    if (!arr || size <= 1)
        return (1);
    i = 0;
    while (i < size - 1)
    {
        if (arr[i] > arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void three_or_less(t_stack *a)
{
    if (*(int *)a->top->content == min_instack(a))
    {
        swap(a);
        rotate(a);
    }
    else if (*(int *)a->top->content == max_instack(a))
    {
        reverse_rotate(a);
        if (*(int *)a->top->content > *(int *)a->top->next->content)
            swap(a);
    }
    else
    {
        if (*(int *)a->top->content > *(int *)a->top->next->content)
            swap(a);
        else
            reverse_rotate(a);
    }
}
void four_sort(t_stack *a)
{
    
}
