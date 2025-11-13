/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:52:12 by malhassa          #+#    #+#             */
/*   Updated: 2025/11/12 11:19:47 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bitsnum(int n)
{
	int	max;

	max = 0;
	while ((n >> max) != 0)
		max++;
	return (max);
}

int	max_instack(t_stack *stack)
{
	t_list	*node;
	int		max;

	node = stack->top;
	max = node->content;
	while (node)
	{
		if (node->content > max)
			max = node->content;
		node = node->next;
	}
	return (max);
}

int	*stacktoarray(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	t_list	*node;

	if (!stack || size <= 0)
		return (NULL);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	node = stack->top;
	i = 0;
	while (node && (i < size))
	{
		arr[i] = (node->content);
		node = node->next;
		i++;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

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

int	issorted(int *arr, int size)
{
	int	i;

	if (!arr || size <= 1)
	{
		free(arr);
		return (1);
	}
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			free(arr);
			return (0);
		}
		i++;
	}
	free(arr);
	return (1);
}
