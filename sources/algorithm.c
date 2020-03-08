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
