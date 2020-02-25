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
** Define whether node is closer to start or end of the stack #2,
** move it to head of the linked list and push it to stack#1. But firstly,
** rotate stack #1.
 */

void	move_node_back(t_push **node1, t_push **node2, t_push **head)
{
	if (len_to_start(*node2) > len_to_end(*node2))
		while ((*node2)->prev != NULL)
			*head = ft_reverse(*head);
	else
		while ((*node2)->prev != NULL)
			*head = ft_rotate(*head);
	*node1 = sort_first_stack(*node1, (*node2)->nbr);
	ft_push(node2, node1);
}

void	sort_stacks(t_push **node1, t_push **node2)
{
	 int i;
	 t_push *head2;

	 while (*node2 != NULL)
	 {
	 	while ((*node2) != NULL)
		{
			i = find_smallest_nbr(*node2);
			head2 = *node2;
			if ((*node2)->nbr == i && *node2 != NULL)
				move_node_back(node1, node2, &head2);
			else if (*node2 != NULL)
				*node2 = (*node2)->next;
			else
				break ;
		}
		 if (*node2 != NULL)
			 *node2 = go_to_start(*node2);
		 else
			 break ;
		i++;
	 }
	 *node1 = sort_first_stack(*node1, find_smallest_nbr(*node1) - 1);
}
