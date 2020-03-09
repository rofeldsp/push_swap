/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:11:51 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/27 15:11:52 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push		*rotate_to_push(t_push *node, t_push *node2, t_push *head, t_output **out)
{
	if (len_to_start(node) > len_to_end(node))
		while (node->prev != NULL)
			head = ft_reverse_out(head, node2, out, 1);
	else
		while (node->prev != NULL)
			head = ft_rotate_out(head, node2, out, 1);
	return (node);
}

int64_t		what_to_move(t_push *node1, t_push *node2)
{
	int 	ticker;
	int 	len2;
	int 	len1;
	int 	buf;
	int64_t	num;

	buf = -1;
	ticker = 1;
	num = 0;
	while (ticker != 0)
	{
		len1 = len_to_push(node1, node2->nbr);
		len2 = len_to_start(node2) > len_to_end(node2) ? len_to_end(node2) :
				len_to_start(node2);
		num = (len2 + len1 + 1 < buf || buf == -1) ? node2->nbr : num;
		buf = (buf == -1) ? (len2 + len1 + 1) : buf;
		buf = (len2 + len1 + 1 < buf) ? (len2 + len1 + 1) : buf;
		ticker = (node2->next == NULL) ? 0 : 1;
		node2 = (ticker == 0) ? node2 : node2->next;
	}
	return (num);
}

void		what_to_push2(t_push **node, int *len_buf)
{
	int		len_to_edge;
	int 	ticker;

	ticker = 0;
	while (ticker != 1)
	{
		if ((*node)->marker == 1)
		{
			len_to_edge = len_to_start(*node) > len_to_end(*node) ?
						  len_to_end(*node) : len_to_start(*node);
			if (len_to_edge < *len_buf || *len_buf == -1)
				*len_buf = len_to_edge;
		}
		if ((*node)->next != NULL)
			*node = (*node)->next;
		else
			ticker = 1;
	}
}

t_push		*what_to_push(t_push *node, t_push *node2, t_output **out)
{
	int		len_buf;
	t_push	*head;

	head = node;
	len_buf = stack_length(node);
	what_to_push2(&node, &len_buf);
	while ((len_to_start(node) != len_buf && len_to_end(node) != len_buf)
			|| node->marker == 0)
		node = node->prev;
	rotate_to_push(node, node2, head, out);
	return (node);
}
