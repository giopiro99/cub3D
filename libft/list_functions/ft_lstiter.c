/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:22:26 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/10 18:06:36 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Applies a function to the content of each node in a linked list.
 *
 * Iterates through the list and applies the function 'f'
 * to each node's content.
 *
 * @param lst Pointer to the first node of the list.
 * @param f Function pointer to apply to the content of each node.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}
/*void print_content(void *content)
{
	printf("%d\n", *((int *)content));
}
int main()
{
	int *val1 = malloc(sizeof(int)),
	*val2 = malloc(sizeof(int)),
	*val3 = malloc(sizeof(int));

	*val1 = 10;
	*val2 = 20;
	*val3 = 30;
	t_list *node1 = ft_lstnew(val1);
	t_list *node2 = ft_lstnew(val2);
	t_list *node3 = ft_lstnew(val3);
	node1->next = node2;
	node2->next = node3;
	ft_lstiter(node1, print_content);
	free(val1);
	free(val2);
	free(val3);
	free(node1);
	free(node2);
	free(node3);
}*/
