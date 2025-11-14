/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputvalidation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:35:43 by malhassa          #+#    #+#             */
/*   Updated: 2025/11/14 19:46:25 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isvalidinput(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			if (argv[i][j + 1])
				j++;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	isinputduplicated(t_stack *a)
{
	t_list	*cur;
	t_list	*check;

	cur = a->top;
	while (cur)
	{
		check = cur->next;
		while (check)
		{
			if (check->content == cur->content)
				return (1);
			check = check->next;
		}
		cur = cur->next;
	}
	return (0);
}

// int	isinputvalid(int argc, char **argv , t_stack *a, int a_size)
// {
	
// }
