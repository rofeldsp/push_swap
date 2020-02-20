/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:11:08 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/20 18:11:09 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	check_sequence(t_push *node)
{
	int 	i;
	int 	num;

	i = 1;
	num = node->nbr;
	while (node->next != NULL)
	{
		if (node->nbr > num)
		{
			num = node->nbr;
			i++;
		}
		node = node->next;
	}
	if (node->nbr > num)
	{
		num = node->nbr;
		i++;
	}
	return (i);
}

int 	buf_sequence(t_push *node1)
{
	int		i;
	int 	len;
	int		sequence_len;
	int 	buf;
	int 	check;

	len = stack_length(node1);
	i = 0;
	sequence_len = 0;
	while (i < len)
	{
		if ((check = check_sequence(node1)) > sequence_len)
		{
			sequence_len = check;
			buf = i;
		}
		node1 = ft_rotate(node1);
		i++;
	}
	return (buf);
}

void	leave_markers(t_push *node1, int buf)
{
	int num;
	int buf2;
	t_push	*node_buf;

	buf2 = buf;
	while (buf-- != 0)
		node1 = ft_rotate(node1);
	node_buf = node1;
	num = node_buf->nbr;
	node_buf = node_buf->next;
	while (node_buf != NULL)
	{
		if (node_buf->nbr > num)
		{
			num = node_buf->nbr;
			node_buf->marker = 0;
		}
		else
			node_buf->marker = 1;
		node_buf = node_buf->next;
	}
	while (buf2-- != 0)
		node1 = ft_reverse(node1);
}

t_push 	*push_2_scnd_stack(t_push *node1)
{
	t_push *node2;

	node2 = malloc(sizeof(t_push));
	node2->nbr = EMPTY_NODE;
	while (node1)
	{
		if (node1->marker == 1)
			ft_push(node1, node2);
		else
			node1 = node1->next;
	}
	return (node2);
}

void	ft_solve(t_push *node1)
{
	int 	buf;
	t_push 	*node2;

	buf = buf_sequence(node1);
	leave_markers(node1, buf); // после этого этапа пропадает указатель на prev - пофиксить
	node2 = push_2_scnd_stack(node1);
}

