/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:42:30 by mohamed           #+#    #+#             */
/*   Updated: 2025/11/08 10:56:52 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"push_swap.h"

int free_with_return(int *value)
{
    free(value);
    return (0);
}
t_list	*ft_newnode(int content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
static int	store_input(int argc, char **argv, t_stack *a)
{
	int		i;
	t_list	*node_a;

	if (argc < 2)
		return (0);
	a->top = NULL;
	a->size = 0;
	i = 1;
	while (i < argc)
	{
		node_a = ft_newnode((int)ft_atoi(argv[i]));
		if (!node_a)
            return(0);
		ft_lstadd_back(&a->top, node_a);
		a->size++;
		i++;
	}
	return (a->size);
}
void	free_stack(t_stack *a)
{
    t_list *tmp;
    t_list *next;

    tmp = a->top;
    while (tmp)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    a->top = NULL;
    a->size = 0;
}
void	free_all(t_stack *a, t_stack *b)
{
    t_list *tmp;
    t_list *next;

    tmp = a->top;
    while (tmp)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    a->top = NULL;
    a->size = 0;
    tmp = b->top;
    while (tmp)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    b->top = NULL;
    b->size = 0;
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
        arr[i] =  (node->content);
        node = node->next;
        i++;
    }
    return (arr);
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
            if ( node->content == arr[j])
            {
                 node->content = j;
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
    max =  node->content;
    while (node)
    {
        if( node->content > max)
            max =  node->content;
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
        if (( stack_a->top->content >> bit) & 1)
        {
            rotate(stack_a);
            write(1,"ra\n",3);
        }
        else
            write(1,push_to_b(stack_a ,stack_b),3);
        i++;
    }
        while(stack_b->size > 0)
            write(1,push_to_a(stack_b,stack_a),3);
        bit++;
    }
}

void    runProgram(t_stack *a , t_stack *b,int argc , char **argv)
{
    if(!store_input(argc,argv,a))
        return(free_all(a,b));
    if (isSorted(stacktoarray(a, a->size), a->size))
        return(free_all(a,b));
    if(a -> size > 5)
    {    
        if(!convert_toindexes(a))
            return(free_all(a,b));
        else
            my_sort(a,b);
    }
    else if (a -> size == 5)
        five_sort(a,b);
    else if (a -> size == 4)
        four_sort(a,b);
    else if (a -> size <= 3)
        three_or_less(a);
    free_all(a,b);
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
    return (0);
}

