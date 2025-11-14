/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:54:17 by malhassa          #+#    #+#             */
/*   Updated: 2025/11/14 15:30:58 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_with_return(int *value)
{
	free(value);
	return (0);
}

int	free_2d_with_return(char **value)
{
	freeptr(value);
	return (0);
}

int	free_all(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	t_list	*next;

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
	return (0);
}

int	free_all_with_error(t_stack *a, t_stack *b)
{
	write(1, "Error\n", 6);
	free_all(a, b);
	return (0);
}

void	freeptr(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
