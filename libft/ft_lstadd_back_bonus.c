/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:30:41 by malhassa          #+#    #+#             */
/*   Updated: 2025/10/27 23:39:40 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

// // ====== test case ======
// int main(void)
// {
//     t_list *list = NULL;
//     t_list *node1;
//     t_list *node2;
//     t_list *node3;

//     int a = 10;
//     int b = 20;
//     int c = 30;

//     node1 = ft_lstnew(&a);
//     node2 = ft_lstnew(&b);
//     node3 = ft_lstnew	(&c);

//     ft_lstadd_back(&list, node1);
//     ft_lstadd_back(&list, node2);
//     ft_lstadd_back(&list, node3);

//     t_list *tmp = list;
//     while (tmp)
//     {
//         printf("%d\n", *(int *)tmp->content);
//         tmp = tmp->next;
//     }
//     return (0);
// }
