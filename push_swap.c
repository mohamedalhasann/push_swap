/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:42:30 by mohamed           #+#    #+#             */
/*   Updated: 2025/10/29 02:06:02 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"push_swap_h.c"

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
void    my_sort(t_stack *stack)
{
    t_stack b;
    int size;

    b.top = NULL;
    b.size = 0;
    size = stack->size;
    
}
int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    a.top = NULL;
    a.size = 0;

    store_input(argc, argv, &a);
    convert_toindexes(&a);
    my_sort(&a);
    printstack(&a);
    // free_all(&a, &b);
    return (0);
}
