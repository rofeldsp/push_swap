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

/*
** Sort stack1 so the head->nbr will be bigger than node-nbr from stack2.
 */

t_push	*sort_first_stack(t_push *node, int nbr, t_output **out)
{
	t_push *head;

	head = node;
	while (nbr > node->nbr)
		node = node->next;
	if (len_to_start(node) > len_to_end(node))
		while ((node)->prev != NULL)
			head = ft_reverse_out(head, out, 1);
	else
		while ((node)->prev != NULL)
			head = ft_rotate_out(head, out, 1);
	node = head;
	return (node);
}

int		len_to_push(t_push *node, int nbr)
{
	while (nbr > node->nbr)
		node = node->next;
	if (len_to_start(node) > len_to_end(node))
		return (len_to_start(node));
	else
		return (len_to_end(node));
}

/*
** Rotate stack, so all the numbers will be in ascending order
 */

t_push	*rotate_ascending(t_push *node, t_output **out)
{
	int i;
	t_push *head;

	head = node;
	i = find_smallest_nbr(node);
	while (node->nbr != i)
		node = node->next;
	if (len_to_start(node) > len_to_end(node))
		while ((node)->prev != NULL)
			head = ft_reverse_out(head, out, 1);
	else
		while ((node)->prev != NULL)
			head = ft_rotate_out(head, out, 1);
	node = head;
	return (node);
}
