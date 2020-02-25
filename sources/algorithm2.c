/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:02:03 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/25 13:02:04 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	len_to_end(t_push *node)
{
	int i;

	i = 0;
	while (node->next != 0)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int 	len_to_start(t_push *node)
{
		int i;

		i = 0;
		while (node->prev != 0)
		{
			i++;
			node = node->prev;
		}
		return (i);
}

t_push	*go_to_start(t_push *node)
{
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}

/*
** Define whether node is closer to start or end of the linked list,
** move it to head of the linked list and push it to stack1.
 */

void	move_node_back(t_push **node1, t_push **node2, t_push **head)
{
	if (len_to_start(*node2) > len_to_end(*node2))
		while ((*node2)->next != NULL)
			*head = ft_reverse(*head);
	else
		while ((*node2)->prev != NULL)
			*head = ft_rotate(*head);
	ft_push(node2, node1);
}

void	sort_stacks(t_push **node1, t_push **node2)
{
	 int i = -2147483648;
//	 t_push *head2;

//	 head2 = *node2;
	 while (i <= 2147483647)
	 {
	 	while ((*node2)->next != NULL)
		{

		}
	 		if ((*node2)->nbr == i)
				move_node_back(node1, node2, node2);

	 }
}
