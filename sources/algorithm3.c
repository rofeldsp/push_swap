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

int		find_smallest_not_indexed(t_push *node)
{
	int i;

	while (node->position != 0)
		node = node->next;
	i = node->nbr;
	while (node != NULL)
	{
		if (node->nbr < i && node->position == 0)
			i = node->nbr;
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

int 	find_largest_nbr(t_push *node)
{
	int i;

	i = node->nbr;
	while (node != NULL)
	{
		if (node->nbr > i)
			i = node->nbr;
		node = node->next;
	}
	return (i);
}

/*
** Sort stack1 so the head->nbr will be bigger than node-nbr from stack2.
 */

t_push	*sort_first_stack(t_push *node, t_push *node2, int nbr, t_output **out)
{
	t_push *head;

	head = node;
	if (nbr > find_largest_nbr(node) || nbr < find_smallest_nbr(node))
	{
		while (node->nbr != find_smallest_nbr(node))
			node = node->next;
	}
	else
	{
		while (node->next != NULL && (!(nbr > node->nbr) ||
									  !(nbr < node->next->nbr)))
			node = node->next;
		if (node->next == NULL)
			return(head);
		else
			node = node->next;

	}
//	while (nbr > node->nbr)
//		node = node->next;
	if (len_to_start(node) > len_to_end(node))
		while ((node)->prev != NULL)
			head = ft_reverse_out(head, node2, out, 1);
	else
		while ((node)->prev != NULL)
			head = ft_rotate_out(head, node2, out, 1);
	node = head;
	return (node);
}

/*
** Calculate a number of steps to rotate stack1 to push node fro, stack2.
 */

int		len_to_push(t_push *node, int nbr)
{
	if (nbr > find_largest_nbr(node) || nbr < find_smallest_nbr(node))
	{
		while (node->nbr != find_smallest_nbr(node))
			node = node->next;
	}
	else
	{
		while (node->next != NULL && (!(nbr > node->nbr) ||
									  !(nbr < node->next->nbr)))
			node = node->next;
		if (node->next == NULL)
			return (0);
		else
			node = node->next;
	}
//	while (node->next != NULL && (!(nbr > node->nbr) ||
//								  !(nbr < node->next->nbr)))
//		node = node->next;
//	if (node->next == NULL)
//		return (0);
	if (len_to_start(node) > len_to_end(node))
		return (len_to_end(node));
	else
		return (len_to_start(node));
}

/*
** Rotate stack, so all the numbers will be in ascending order
 */

t_push	*rotate_ascending(t_push *node, t_push *node2, t_output **out)
{
	int i;
	t_push *head;

	head = node;
	i = find_smallest_nbr(node);
	while (node->nbr != i)
		node = node->next;
	if (len_to_start(node) > len_to_end(node))
		while ((node)->prev != NULL)
			head = ft_reverse_out(head, node2, out, 1);
	else
		while ((node)->prev != NULL)
			head = ft_rotate_out(head, node2, out, 1);
	node = head;
	return (node);
}
