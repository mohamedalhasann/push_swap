/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputvalidation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:35:43 by malhassa          #+#    #+#             */
/*   Updated: 2025/11/14 01:16:37 by mohamed          ###   ########.fr       */
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
				return (0);
			}
		}
		i++;
	}
	return (1);
}
