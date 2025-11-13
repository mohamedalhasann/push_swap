/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputvalidation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:35:43 by malhassa          #+#    #+#             */
/*   Updated: 2025/11/13 16:55:29 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isvalidinput(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			if(argv[i][j + 1])
				j++;
		while(argv[i][j])
		{
			if(argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
			{
				freeptr(argv);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
