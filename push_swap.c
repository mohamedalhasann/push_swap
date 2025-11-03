/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:42:30 by mohamed           #+#    #+#             */
/*   Updated: 2025/11/01 22:58:44 by mohamed          ###   ########.fr       */
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
int *stacktoarray(t_stack *stack, int size)
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
void convert_toindexes(t_stack *stack)
{
    int j;
    int *arr;
    t_list *node;
    
    if(!stack)
        return ;
    arr = stacktoarray(stack,stack->size);    
    sort_array(arr,stack->size);
    node = stack->top;
    while (node)
    {
        int j = 0;
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

int bitsnum(int n)
{
    int max;

    max = 0;
    while((n >> max) != 0)
        max++;
    return (max);
}
char    *my_sort(t_stack *stack_a,t_stack *stack_b)
{
    int size;
    int bit;
    int i;
    char    *result;
    
    if (!stack_a || !*stack_a || stack_a->size < 2)
        return;
    bit = 0;
    result = malloc(10000); 
    result[0] = '\0';
    while (bit < bitsnum(max_instack(stack_a)))
    {
        i = 0;
        size = stack_a -> size;
        while (i < size)
        {
            if ((*(int *)stack_a->top->content >> bit) & 1)
                strcat(result,rotate(stack_a)
            else 
                strcat(result,push_to_b(stack_a ,stack_b));
            i++;
        }
        while(stack_b->size > 0)
            strcat(result,push_to_a(stack_b,stack_a));
        bit++;
    }
    return (result);
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
    printf("%s",my_sort(&a,&b));
    // printstack(&a);
    // free_all(&a, &b);
    return (0);
}
