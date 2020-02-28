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

t_push *rotate_to_push(t_push *node, t_push *head, t_output **out)
{
	if (len_to_start(node) > len_to_end(node))
		while (node->prev != NULL)
			head = ft_reverse_out(head, out, 1);
	else
		while (node->prev != NULL)
			head = ft_rotate_out(head, out, 1);
	return (node);
}

int		what_to_move(t_push *node1, t_push *node2)
{
	int 	ticker;
	int 	len2;
	int 	len1;
	int 	buf;
	int 	num;

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
// посчитать здесь в цикле, сколько уйдет для каждой фигуры шагов, чтобы ее
// переместить обратно. Выбрать, что перемещаем, и вернуть указатель на этот
// элемент списка.
}

t_push	*what_to_push(t_push *node, t_output **out)
{
	int		len_to_edge;
	int		len_buf;
	int 	ticker;
	t_push	*head;

	head = node;
	len_buf = stack_length(node);
	ticker = 0;
	while (ticker != 1)
	{
		if (node->marker == 1)
		{
			len_to_edge = len_to_start(node) > len_to_end(node) ?
						  len_to_end(node) : len_to_start(node);
			if (len_to_edge < len_buf || len_buf == -1)
				len_buf = len_to_edge;
		}
		if (node->next != NULL)
			node = node->next;
		else
			ticker = 1;
	}
	while ((len_to_start(node) != len_buf && len_to_end(node) != len_buf)
			|| node->marker == 0)
		node = node->prev;
	rotate_to_push(node, head, out);
	return (node);
}

t_output *put_rr(t_output **out)
{
	t_output	*head;
	int			switcher;

	head = *out;
	switcher = 1;
	while (!((*out)->oper & ROT_A) && !((*out)->oper & ROT_B))
		*out = (*out)->prev;
	if ((*out)->oper & ROT_A)
		*out = delete_node(out);
	else if ((*out)->oper & ROT_B)
	{
		switcher = 2;
		(*out)->oper = RR;
	}
	while (!((*out)->oper & (switcher == 1 ? ROT_B : ROT_A)))
		*out = (*out)->prev;
	if (switcher == 1)
		(*out)->oper = RR;
	else
		*out = delete_node(out);
	return (head);
}

t_output *put_rrr(t_output **out)
{
	t_output	*head;
	int			switcher;

	head = *out;
	switcher = 1;
	while (!((*out)->oper & RROT_A) && !((*out)->oper & RROT_B))
		*out = (*out)->prev;
	if ((*out)->oper & RROT_A)
		*out = delete_node(out);
	else if ((*out)->oper & RROT_B)
	{
		switcher = 2;
		(*out)->oper = RRR;
	}
	while (!((*out)->oper & (switcher == 1 ? RROT_B : RROT_A)))
		*out = (*out)->prev;
	if (switcher == 1)
		(*out)->oper = RRR;
	else
		*out = delete_node(out);
	return (head);
}
