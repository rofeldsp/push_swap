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

int		len_to_end(t_push *node)
{
	int i;

	i = 0;
	while (node->next != NULL)
	{
		i++;
		node = node->next;
	}
	return (i + 1);
}

int		len_to_start(t_push *node)
{
	int i;

	i = 0;
	while (node->prev != NULL)
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

void	move_node_back(t_push **node1, t_push **node2, t_push **head,
															t_output **out)
{
	if (len_to_start(*node2) > len_to_end(*node2))
		while ((*node2)->prev != NULL)
			*head = ft_reverse_out(*head, *node1, out, 2);
	else
		while ((*node2)->prev != NULL)
			*head = ft_rotate_out(*head, *node1, out, 2);
	*node1 = sort_first_stack(*node1, *node2, (*node2)->nbr, out);
	ft_push_out(node2, node1, out, 2);
}

void	sort_stacks(t_push **node1, t_push **node2, t_output **out)
{
	t_push	*head2;
	int		move_nbr;

	while (*node2 != NULL)
	{
		if ((*node2)->nbr == EMPTY_NODE)
			break ;
		move_nbr = what_to_move(*node1, *node2);
		head2 = go_to_start(*node2);
		while ((*node2)->nbr != move_nbr)
			*node2 = (*node2)->next;
		move_node_back(node1, node2, &head2, out);
	}
	*node1 = rotate_ascending(*node1, *node2, out);
}
