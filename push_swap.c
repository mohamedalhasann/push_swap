/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:42:30 by mohamed           #+#    #+#             */
/*   Updated: 2025/10/29 15:47:47 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"push_swap.h"

void store_input(int argc, char **argv, t_stack *a)
{
    int i;
    t_list *node_a;
    int *value;

    if (argc < 2)
    {
        printf("no arguments passed\n");
        return;
    }
    a->top = NULL;
    a->size = 0;
    i = 1;
    while (i < argc)
    {
        value = malloc(sizeof(int));
        if (!value)
            return;
        *value = ft_atoi(argv[i]); 
        node_a = ft_lstnew(value); 
        if (!node_a)
            return;
        ft_lstadd_back(&a->top, node_a);
        a->size++;
        i++;
    }
}

void    sort_stack(t_stack *a,t_stack *b)
{
    
}
void    printstack(t_stack  *stack)
{
    t_list *node;

    node = stack -> top;
    while (node)
    {
        printf("%d ",*(int *)(node -> content));
        node = node -> next;
    }
    printf("\n");
}
void sort_array(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

void convert_toindexes(t_stack *stack)
{
    int i;
    int size;
    int *arr;
    t_list *node;
    
    i = 0;
    size = stack->size;
    node = stack->top;
    arr = malloc(sizeof(int) * size);
    if(!arr)
        return;
    while (i < size && node)
    {
        arr[i] = *(int *)(node->content);
        node = node->next;
        i++;
    }
    sort_array(arr,size);
    i = 0;
    node = stack->top;
    while (node)
    {
        int j = 0;
        while (j < size)
        {
            if (*(int *)node->content == arr[j])
            {
                *(int *)node->content = j;
                break;
            }
        j++;
        }
    node = node->next;
    }
    free(arr);
}
int max_instack(t_stack *stack)
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

int maxbits(int n)
{
    int max;

    max = 0;
    while((n >> max) != 0) //?
        max++;
    return (max);
}
void    my_sort(t_stack *stack_a,t_stack *stack_b)
{
    int size;
    int bit;
    int maxbit;
    int maxnum;
    int i;
    
    maxnum = max_instack(stack_a);
    maxbit = maxbits(maxnum);
    bit = 0;
    while (bit < maxbit)
    {
        i = 0;
        size = stack_a -> size;
        while (i < size)
        {
            if ((*(int *)stack_a->top->content >> bit) & 1)
                rotate(stack_a);
            else 
                push(stack_a ,stack_b);
            i++;
        }
        while(stack_b->size > 0)
            push(stack_b,stack_a);
        bit++;
    }
}
int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;

    store_input(argc, argv, &a);
    convert_toindexes(&a);
    my_sort(&a,&b);
    printstack(&a);
    // free_all(&a, &b);
    return (0);
}
