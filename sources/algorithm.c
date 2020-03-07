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

int 	check_index_sequence(t_push *node)
{
	int 	i;
	int 	num;

	i = 1;
	num = node->index;
	while (node->next != NULL)
	{
		if (node->index == num + i)
			i++;
		node = node->next;
	}
	if (node->index == num + i)
		i++;
	return (i);
}

int 	best_sequence(t_push *node)
{
	int len;
	int swap_len;
	int index_len;
	int index_swap;

	len = check_sequence(node);
	node = ft_swap(node);
	swap_len = check_sequence(node);
	index_swap = check_index_sequence(node);
	node = ft_swap(node);
	index_len = check_index_sequence(node);
	index_len = index_swap > index_len ? index_swap : index_len;
	len = index_len > len ? index_len : len;
	return (swap_len > len ? swap_len : len);
}

void	put_index(t_push **node)
{
	int64_t 	smallest_n;
	int 	i;
	int 	j;

	i = 1;
	j = 0;
	while ((smallest_n = find_smallest_not_indexed(*node)) != ALL_INDEXED)
	{
//		smallest_n = find_smallest_not_indexed(*node);
		while ((*node)->nbr != smallest_n)
		{
			*node = ft_rotate(*node);
			j++;
		}
		(*node)->index = i++;
	}
	while (j-- != 0)
		*node = ft_reverse(*node);
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

void	leave_marks_by_index(t_push **node1, int buf, int swapper)
{
	t_push	*head;
	int 	index_num;

	head = *node1;
	index_num = (*node1)->index;
//	(*node1)->marker |= 0;
	(*node1) = (*node1)->next;
	while (*node1 != NULL)
	{
		if ((*node1)->index == index_num + 1)
//		{
			index_num = (*node1)->index;
//			(*node1)->marker |= 0;
//		}
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
		if (best_sequence(*node1) == check_index_sequence(*node1))
		{
			leave_marks_by_index(node1, buf2, swapper);
			return (0);
		}
		else
		{
			(*node1)->marker = 2;
			*node1 = ft_swap(*node1);
			swapper = 1;
			if (check_index_sequence(*node1) > check_sequence(*node1))
			{
				leave_marks_by_index(node1, buf2, swapper);
				return (swapper);
			}
		}
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

int 	find_smallest_marked(t_push *node)
{
	int i;

	while (node->marker != 1)
		node = node->next;
	i = node->nbr;
	while (node != NULL)
	{
		if (node->nbr < i && node->marker == 1)
			i = node->nbr;
		node = node->next;
	}
	return (i);
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
//		head = *node1;
//		num = find_smallest_marked(*node1);
//		while ((*node1)->nbr != num)
//			*node1 = (*node1)->next;
//		*node1 = rotate_to_push(*node1, node2, head, out);
		*node1 = what_to_push(*node1, node2, out);
//		*node1 = ft_rotate_out(*node1, node2, out, 1);
//		if (node2->nbr != EMPTY_NODE)
//			node2 = sort_first_stack(node2, *node1, (*node1)->nbr, out);
		if ((*node1)->marker == 1)
			ft_push_out(node1, &node2, out, 1);

//		buf = buf_sequence(*node1);
//		swapper2 = leave_marks(node1, buf);
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
//	if (swapper == 1)
//	{
//		head = *node1;
//		while ((*node1)->marker != 2)
//			*node1 = (*node1)->next;
//		head = rotate_to_push(*node1, node2, head, out);
//		*node1 = head;
//		*node1 = ft_swap_out(*node1, node2, out, 1);
//	}
	return (node2);
}

void	mark_stack(t_push **node1, int i, int iters)
{
	t_push *head;
	int median;

	median = stack_length(*node1) / iters;
	head = *node1;
	put_index(node1);
	while ((*node1)->next != NULL)
	{
		if ((*node1)->index >= median * i && (i + 1 == iters ? 1 : (*node1)->index < median * (i + 1)))
			(*node1)->marker = 1;
		*node1 = (*node1)->next;
	}
	*node1 = head;
}

void	mark_stack2(t_push **node1)
{
	t_push *head;
	int median;

	median = stack_length(*node1) / 3;
	head = *node1;
	put_index(node1);
	while ((*node1)->next != NULL)
	{
		if ((*node1)->index >= median && (*node1)->index < median * 2)
			(*node1)->marker = 1;
		*node1 = (*node1)->next;
	}
	*node1 = head;
}

void	mark_stack3(t_push **node1)
{
	t_push *head;
	int median;

	median = stack_length(*node1) / 3;
	head = *node1;
	put_index(node1);
	while ((*node1)->next != NULL)
	{
		if ((*node1)->index >= median * 2)// && (*node1)->index < median * 3)
			(*node1)->marker = 1;
		*node1 = (*node1)->next;
	}
	*node1 = head;
}

void	mark_stack4(t_push **node1)
{
	t_push *head;
	int median;

	median = stack_length(*node1) / 5;
	head = *node1;
	put_index(node1);
	while ((*node1)->next != NULL)
	{
		if ((*node1)->index >= median * 3 && (*node1)->index < median * 4)
			(*node1)->marker = 1;
		*node1 = (*node1)->next;
	}
	*node1 = head;
}

void	mark_stack5(t_push **node1)
{
	t_push *head;
	int median;

	median = stack_length(*node1) / 5;
	head = *node1;
	put_index(node1);
	while ((*node1)->next != NULL)
	{
		if ((*node1)->index >= median * 4)
			(*node1)->marker = 1;
		*node1 = (*node1)->next;
	}
	*node1 = head;
}

void 	free_marks(t_push **node1)
{
	t_push	*head;

	head = *node1;
	while (*node1 != NULL)
	{
		(*node1)->marker = 0;
		*node1 = (*node1)->next;
	}
	*node1 = head;
}

/*
** Function responsible for finding solution. We use swapper in different
** situations, because of 5 variable limitation of ecole 42.
 */

void	ft_solve(t_push **node1)
{
	int 		buf;
	t_push 		*node2;
	t_output	*out;
	int 		swapper;
	int 		iterations;

	out = allocate_output_struct(sizeof(t_output));
//	buf = buf_sequence(*node1);
//	swapper = leave_marks(node1, buf); // после этого этапа пропадает указатель на prev - пофиксить
	if (stack_length(*node1) <= 50)
	{
		buf = buf_sequence(*node1);
		swapper = leave_marks(node1, buf); // после этого этапа пропадает указатель на prev - пофиксить
		node2 = push_to_scnd_stack(node1, &out, swapper);
		sort_stacks(node1, &node2, &out);
	}
	else if (stack_length(*node1) <= 200)
	{
		iterations = 1;
		swapper = 0;
		while (swapper < iterations)
		{
			mark_stack(node1, swapper, iterations);
			node2 = push_to_scnd_stack(node1, &out, 0);
			sort_stacks(node1, &node2, &out);
			free_marks(node1);
			swapper++;
		}
	}
	else
	{
		iterations = 3;
		swapper = 0;
		while (swapper < iterations)
		{
			mark_stack(node1, swapper, iterations);
			node2 = push_to_scnd_stack(node1, &out, 0);
			sort_stacks(node1, &node2, &out);
			free_marks(node1);
			swapper++;
		}
	}
	while (out->prev != NULL)
		out = out->prev;
	out = combine_rotations(&out);
	display_output(out);
	free_output(out);
	free_node(*node1);
}
