/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:12:41 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/28 12:12:42 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Find the longest sequence of sorted ints in the stack and remember
** its starting point
*/

#include "push_swap.h"

int			buf_sequence(t_push *node1)
{
	int		i;
	int		len;
	int		sequence_len;
	int		buf;
	int		check;

	len = stack_length(node1);
	i = 0;
	sequence_len = 0;
	put_index(&node1);
	while (i < len)
	{
		if ((check = best_sequence(node1)) > sequence_len)
		{
			sequence_len = check;
			buf = i;
		}
		node1 = ft_rotate(node1);
		i++;
	}
	return (buf);
}

void		leave_marks_by_index(t_push **node1, int buf, int swapper)
{
	t_push	*head;
	int		index_num;

	head = *node1;
	index_num = (*node1)->index;
	(*node1) = (*node1)->next;
	while (*node1 != NULL)
	{
		if ((*node1)->index == index_num + 1)
			index_num = (*node1)->index;
		else
			(*node1)->marker = 1;
		*node1 = (*node1)->next;
	}
	*node1 = head;
	if (swapper == 1)
		*node1 = ft_swap(*node1);
	while (buf-- != 0)
		*node1 = ft_reverse(*node1);
}

/*
** Mark all nodes which are out of order and should be pushed to stack2.
*/

int			leave_marks(t_push **node1, int buf)
{
	int buf2;
	int swapper;

	buf2 = buf;
	swapper = 0;
	while (buf-- != 0)
		*node1 = ft_rotate(*node1);
	if ((swapper = leave_marks2(node1, buf2, swapper)) >= 0)
		return (swapper);
	else if (swapper == -2)
		swapper = 1;
	leave_marks3(node1);
	if (swapper == 1)
		*node1 = ft_swap(*node1);
	while (buf2-- != 0)
		*node1 = ft_reverse(*node1);
	return (swapper);
}

/*
** Push all marked items of stack to stack2.
*/

t_push		*push_to_scnd_stack(t_push **node1, t_output **out, int swapper)
{
	t_push	*node2;
	t_push	*head;

	node2 = allocate_struct(sizeof(t_push));
	node2->nbr = EMPTY_NODE;
	while (count_marked_nodes(*node1) > 0)
	{
		*node1 = what_to_push(*node1, node2, out);
		if ((*node1)->marker == 1)
			ft_push_out(node1, &node2, out, 1);
	}
	if (swapper == 1)
	{
		head = *node1;
		while ((*node1)->marker != 2)
			*node1 = (*node1)->next;
		head = rotate_to_push(*node1, node2, head, out);
		*node1 = head;
		*node1 = ft_swap_out(*node1, node2, out, 1);
	}
	return (node2);
}

void		mark_stack(t_push **node1, int i, int iters)
{
	t_push		*head;
	int			median;

	median = stack_length(*node1) / iters;
	head = *node1;
	put_index(node1);
	while ((*node1)->next != NULL)
	{
		if ((*node1)->index >= median * i && (i + 1 == iters ? 1 :
											(*node1)->index < median * (i + 1)))
			(*node1)->marker = 1;
		*node1 = (*node1)->next;
	}
	*node1 = head;
}
