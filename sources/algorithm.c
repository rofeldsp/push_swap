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
		i++;
	return (i);
}

int 	best_sequence(t_push *node)
{
	int len;
	int swap_len;

	len = check_sequence(node);
	node = ft_swap(node);
	swap_len = check_sequence(node);
	node = ft_swap(node);
	return (swap_len > len ? swap_len : len);
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

/*
** Mark all nodes which are out of order and should be pushed to stack2.
 */

int		leave_marks(t_push **node1, int buf)
{
	int num;
	int buf2;
	int swapper;
	t_push	*head;

	buf2 = buf;
	swapper = 0;
	while (buf-- != 0)
		*node1 = ft_rotate(*node1);
	if (best_sequence(*node1) > check_sequence(*node1))
	{
		(*node1)->marker = 2;
		*node1 = ft_swap(*node1);
		swapper = 1;
	}
	head = *node1;
	num = (*node1)->nbr;
//	(*node1)->marker |= 0;
	(*node1) = (*node1)->next;
	while (*node1 != NULL)
	{
		if ((*node1)->nbr > num)
//		{
			num = (*node1)->nbr;
//			(*node1)->marker |= 0;
//		}
		else
			(*node1)->marker = 1;
		*node1 = (*node1)->next;
	}
	*node1 = head;
	if (swapper == 1)
		*node1 = ft_swap(*node1);
	while (buf2-- != 0)
		*node1 = ft_reverse(*node1);
	return (swapper);
}

/*
** Push all marked items of stack to stack2.
 */

t_push 	*push_to_scnd_stack(t_push **node1, t_output **out, int swapper)
{
	t_push	*node2;
	t_push	*head;

	node2 = allocate_struct(sizeof(t_push));
	node2->nbr = EMPTY_NODE;
//	if (best_sequence(*node1) > check_sequence(*node1))
//		*node1 = ft_swap_out(*node1, node2, out, 1);
	while (count_marked_nodes(*node1) > 0)
	{
		*node1 = what_to_push(*node1, node2, out);
		if ((*node1)->marker == 1)
			ft_push_out(node1, &node2, out, 1);
//		else
//			*node1 = ft_rotate_out(*node1, node2, out, 1);
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

/*
 * Function responsible for finding solution
 */

void	ft_solve(t_push **node1)
{
	int 		buf;
	t_push 		*node2;
	t_output	*out;
	int 		swapper;

	out = allocate_output_struct(sizeof(t_output));
	buf = buf_sequence(*node1);
	swapper = leave_marks(node1, buf); // после этого этапа пропадает указатель на prev - пофиксить
	node2 = push_to_scnd_stack(node1, &out, swapper);
	sort_stacks(node1, &node2, &out);
	while (out->prev != NULL)
		out = out->prev;
	out = combine_rotations(&out);
	display_output(out);
	free_output(out);
	free_node(*node1);
}
