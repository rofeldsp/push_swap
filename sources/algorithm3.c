/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:09:10 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/25 18:09:11 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	count_marked_nodes(t_push *node)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		if (node->marker == 1)
			i++;
		node = node->next;
	}
	return (i);
}

int 	find_smallest_nbr(t_push *node)
{
	int i;

	i = node->nbr;
	while (node != NULL)
	{
		if (node->nbr < i)
			i = node->nbr;
		node = node->next;
	}
	return (i);
}

t_push	*sort_first_stack(t_push *node, int nbr)
{
	t_push *head;

	head = node;
	while (nbr > node->nbr)
		node = node->next;
	if (len_to_start(node) > len_to_end(node))
		while ((node)->prev != NULL)
			head = ft_reverse(head);
	else
		while ((node)->prev != NULL)
			head = ft_rotate(head);
	node = head;
	return (node);
}

