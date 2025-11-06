/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:42:30 by mohamed           #+#    #+#             */
/*   Updated: 2025/11/06 18:02:36 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"push_swap.h"

static void store_input(int argc, char **argv, t_stack *a)
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
void free_stack(t_stack *stack)
{
    t_list *current = stack->top;
    t_list *tmp;

    while (current)
    {
        tmp = current->next;
        free(current->content); 
        free(current);
        current = tmp;
    }
    stack->top = NULL;
    stack->size = 0;
}


static void    printstack(t_stack  *stack)
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
static void sort_array(int *arr, int size)
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
static int isSorted(int *arr, int size)
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

static int convert_toindexes(t_stack *stack)
{
    int j;
    int *arr;
    t_list *node;
    
    if(!stack || stack -> size < 2)
        return (0);
    arr = stacktoarray(stack,stack->size);
    sort_array(arr, stack->size); 
    node = stack->top;
    while (node)
    {
        j = 0;
        while (j < stack->size)
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
    return (1);
}
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

static int bitsnum(int n)
{
    int max;

    max = 0;
    while((n >> max) != 0)
        max++;
    return (max);
}
static void    my_sort(t_stack *stack_a,t_stack *stack_b)
{
    int bit;
    int i;
    int size;
    
    bit = 0;
    while (bit < bitsnum(max_instack(stack_a)))
    {
        i = 0;
        size = stack_a->size;
        while (i < size)
        {
        if ((*(int *)stack_a->top->content >> bit) & 1)
        {
            rotate(stack_a);
            write(1,"ra\n",3);
        }
        else
        {
            push_to_b(stack_a ,stack_b);
            write(1,"pb\n",3);
        }
        i++;
    }
        while(stack_b->size > 0)
        {
            push_to_a(stack_b,stack_a);
            write(1,"pa\n",3);
        }
        bit++;
    }
}


void    runProgram(t_stack *a , t_stack *b,int argc , char **argv)
{
    store_input(argc,argv,a);  
    if (isSorted(stacktoarray(a, a->size), a->size))
    {
        free_stack(a);
        return;
    }
    if( a-> size > 5)
    {
        if(!convert_toindexes(a))
            return;
    }
    if(a -> size > 5)
        my_sort(a,b);
    else if (a -> size == 5)
        five_sort(a,b);
    else if (a -> size == 4)
        four_sort(a,b);
    else if (a -> size <= 3)
        three_or_less(a);
    free_stack(a);
}
int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;
        runProgram(&a,&b,argc,argv);
    
    // printstack(&a);
    // free_all(&a, &b);
    return (0);
}

