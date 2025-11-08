/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:29:54 by malhassa          #+#    #+#             */
/*   Updated: 2025/11/08 10:57:32 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int	content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

// int main(void)
// {
//     t_list *node;

//     int x = 42;
//     node = ft_lstnew(&x);
//     t_list *node2;
//     char y = 'n';
//     node2 = ft_lstnew(&y);

//     if (node && node2)
//     {
// 		printf("Content :%d\n",*(int *)node->content);
// 	    printf("Next: %p\n", node->next);
//         printf("Content: %c\n", *(int *)node2->content);
//         printf("Next: %p\n", (void *)node2->next);
//     }

// }