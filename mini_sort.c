/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:33:35 by malhassa          #+#    #+#             */
/*   Updated: 2025/11/05 17:55:40 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int max_instack(t_stack *stack)
{
    t_list *node = stack->top;
    int max = *(int *)node->content;

    while (node)
    {
        if (*(int *)node->content > max)
            max = *(int *)node->content;
        node = node->next;
    }
    return (max);
}

int min_instack(t_stack *stack)
{
    t_list *node = stack->top;
    int min = *(int *)node->content;

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
    int i = 0;
    while (i < size - 1)
    {
        if (arr[i] > arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}
static int *stacktoarray(t_stack *stack, int size)
{
    int *arr;
    int i;
    t_list  *node;

    if (!stack || size <= 0)
        return (NULL);
    arr = malloc(sizeof(int) * size);
    if(!arr)
        return (NULL);
    node = stack->top;
    i = 0;
    while (node && (i < size))
    {
        arr[i] = *(int *)(node->content);
        node = node->next;
        i++;
    }
    return (arr);
}
void three_or_less(t_stack *a)
{
    if (isSorted(stacktoarray(a,a->size),a->size))
        return;
    if (*(int *)a->top->content == min_instack(a))
    {
        swap(a);
        write(1,"sa\n",3);
        rotate(a);
        write(1,"ra\n",3);
    }
    else if (*(int *)a->top->content == max_instack(a))
    {
        rotate(a);
        write(1,"ra\n",3);
        if (*(int *)a->top->content > *(int *)a->top->next->content)
        {    
            swap(a);
            write(1,"sa\n",3);
        }    
    }
    else
    {
        if (*(int *)a->top->content > *(int *)a->top->next->content)
        {
            swap(a);
            write(1,"sa\n",3);
        }
        else
        {
            reverse_rotate(a);
            write(1,"rra\n",4);
        }
}
}

void four_sort(t_stack *a, t_stack *b)
{
    while (*(int *)a->top->content != min_instack(a))
    {
        rotate(a);
        write(1, "ra\n", 3);
    }
    push_to_b(a, b);
    write(1, "pb\n", 3);
    three_or_less(a);
    push_to_a(b, a);
    write(1, "pa\n", 3);
}

void five_sort(t_stack *a, t_stack *b)
{
    while (*(int *)a->top->content != min_instack(a))
    {
        rotate(a);
        write(1, "ra\n", 3);
    }
    push_to_b(a, b);
    write(1, "pb\n", 3);
    while (*(int *)a->top->content != min_instack(a))
    {
        rotate(a);
        write(1, "ra\n", 3);
    }
    push_to_b(a, b);
    write(1, "pb\n", 3);
    three_or_less(a);
    push_to_a(b, a);
    write(1, "pa\n", 3);
    push_to_a(b, a);
    write(1, "pa\n", 3);
}
