/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:42:30 by mohamed           #+#    #+#             */
/*   Updated: 2025/11/13 17:00:29 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	store_input(int argc, char **argv, t_stack *a)
{
	char	**split;
	int		i;
	int		j;
	t_list	*node;

	if (argc < 2)
		return (0);
	j = 1;
	while (j < argc)
	{
		split = ft_split(argv[j], ' ');
		if (!split)
			return (0);
		if (!isvalidinput(split))
			return (0);
		i = 0;
		while (split[i])
		{
			node = malloc(sizeof(t_list));
			if (!node)
				return (0);
			node->content = ft_atoi(split[i]);
			if (node -> content >= 2147483647 || node -> content <= -2147483648)
			{
				free(node);
				freeptr(split);
				return (0);
			}
			node->next = NULL;
			ft_lstadd_back(&a->top, node);
			a->size++;
			i++;
		}
		freeptr(split);
		j++;
	}
	return (a->size);
}

static int	convert_toindexes(t_stack *stack)
{
	int		j;
	int		*arr;
	t_list	*node;

	if (!stack || stack->size < 2)
		return (0);
	arr = stacktoarray(stack, stack->size);
	sort_array(arr, stack->size);
	node = stack->top;
	while (node)
	{
		j = 0;
		while (j < stack->size)
		{
			if (node->content == arr[j])
			{
				node->content = j;
				break ;
			}
			j++;
		}
		node = node->next;
	}
	free(arr);
	return (1);
}

static void	my_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bit;
	int	i;
	int	size;

	bit = 0;
	while (bit < bitsnum(max_instack(stack_a)))
	{
		i = 0;
		size = stack_a->size;
		while (i < size)
		{
			if ((stack_a->top->content >> bit) & 1)
				rotate(stack_a, 'a');
			else
				write(1, push_to_b(stack_a, stack_b), 3);
			i++;
		}
		while (stack_b->size > 0)
			write(1, push_to_a(stack_b, stack_a), 3);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	if (!store_input(argc, argv, &a))
		return (free_all(&a, &b));
	if (issorted(stacktoarray(&a, a.size), a.size))
		return (free_all(&a, &b));
	if (a.size > 5)
	{
		if (!convert_toindexes(&a))
			return (free_all(&a, &b));
		else
			my_sort(&a, &b);
	}
	else if (a.size == 5)
		five_sort(&a, &b);
	else if (a.size == 4)
		four_sort(&a, &b);
	else if (a.size <= 3)
		three_or_less(&a);
	return (free_all(&a, &b));
}
