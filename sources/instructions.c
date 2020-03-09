/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:11:55 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/20 14:11:57 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push		*ft_swap(t_push *node)
{
	t_push *tmp;

	if (node->next == NULL)
		return (node);
	tmp = node->next;
	node->next->next->prev = node;
	node->next = node->next->next;
	node->prev = tmp;
	tmp->next = node;
	tmp->prev = NULL;
	return (tmp);
}

void		ft_push(t_push **node1, t_push **node2)
{
	t_push *tmp;

	if (*node1 == NULL || (*node1)->nbr == EMPTY_NODE)
		print_error();
	tmp = (*node1)->next;
	if ((*node2)->nbr == EMPTY_NODE)
	{
		free(*node2);
		*node2 = *node1;
		(*node2)->next = NULL;
		(*node2)->prev = NULL;
	}
	else
	{
		(*node1)->next = *node2;
		(*node2)->prev = *node1;
		*node2 = *node1;
	}
	*node1 = tmp;
	if (*node1 != NULL)
		(*node1)->prev = NULL;
}

t_push		*ft_rotate(t_push *node)
{
	t_push	*tmp;
	t_push	*head;

	if (node == NULL || node->next == NULL)
		return (node);
	head = node->next;
	tmp = node->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
	node->prev = tmp;
	head->prev = NULL;
	return (head);
}

t_push		*ft_reverse(t_push *node)
{
	t_push	*tmp;

	if (node == NULL || node->next == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	tmp = node;
	node = node->prev;
	node->next = NULL;
	while (node->prev != NULL)
		node = node->prev;
	node->prev = tmp;
	node->prev->next = node;
	node = node->prev;
	node->prev = NULL;
	return (node);
}
