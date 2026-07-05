/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputvalidation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:35:43 by malhassa          #+#    #+#             */
/*   Updated: 2025/11/17 00:59:34 by mohamed          ###   ########.fr       */
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

int	isinputduplicated(int *arr, int size)
{
    int i;
    int j;

	if(!arr)
		return (0);
    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
			{
				free(arr);
                return (1);
			}
            j++;
        }
        i++;
    }
	free(arr);
    return (0);
}

