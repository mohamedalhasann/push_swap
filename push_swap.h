/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:19:29 by mohamed           #+#    #+#             */
/*   Updated: 2025/11/13 16:56:39 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
}			t_stack;
void	swap(t_stack *stack, char c);
void	rotate(t_stack *stack, char c);
void	reverse_rotate(t_stack *stack, char c);
char	*push_to_b(t_stack *src, t_stack *dest);
char	*push_to_a(t_stack *src, t_stack *dest);
void	three_or_less(t_stack *a);
void	four_sort(t_stack *a, t_stack *b);
void	five_sort(t_stack *a, t_stack *b);
int		min_instack(t_stack *stack);
int		max_instack(t_stack *stack);
int		bitsnum(int n);
int		*stacktoarray(t_stack *stack, int size);
void	sort_array(int *arr, int size);
int		issorted(int *arr, int size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_newnode(int content);
int		free_all(t_stack *a, t_stack *b);
int		free_with_return(int *value);
void	freeptr(char **ptr);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
int isvalidinput(char **argv);

#endif
