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

/*
** Find the longest sequence of sorted ints in the stack and remember
** its starting point
 */

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

/*
** Mark all nodes which are out of order and should be pushed to stack2.
 */

void	leave_marks(t_push *node1, int buf)
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

/*
** Push all marked items of stack to stack2.
 */

t_push 	*push_to_scnd_stack(t_push **node1, t_output **out)
{
	t_push *node2;

	node2 = allocate_struct(sizeof(t_push));
	node2->nbr = EMPTY_NODE;
	while (count_marked_nodes(*node1) > 0)
	{
		if ((*node1)->marker == 1)
			ft_push_out(node1, &node2, out, 1);
		else
			*node1 = ft_rotate_out(*node1, out, 1);
	}
	return (node2);
}

/*
 * Function responsible for finding solution
 */

void	ft_solve(t_push *node1)
{
	int 		buf;
	t_push 		*node2;
	t_output	*out;

	out = allocate_output_struct(sizeof(t_output));
	buf = buf_sequence(node1);
	leave_marks(node1, buf); // после этого этапа пропадает указатель на prev - пофиксить
	node2 = push_to_scnd_stack(&node1, &out);
	sort_stacks(&node1, &node2, &out);
	while (out->prev != NULL)
		out = out->prev;
	out = combine_rotations(&out);
	display_output(out);
}

