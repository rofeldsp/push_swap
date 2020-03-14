/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:09:51 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/03/14 15:09:52 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		add_to_stack(t_push *node, t_push **node2)
{
	t_push	*new_node;

	while ((*node2)->next != NULL)
		*node2 = (*node2)->next;
	new_node = allocate_struct(sizeof(t_push));
	*new_node = *node;
	new_node->prev = *node2;
	new_node->next = NULL;
	(*node2)->next = new_node;
}

t_push		*copy_stack(t_push *node)
{
	t_push	*node2;

	node2 = allocate_struct(sizeof(t_push));
	*node2 = *node;
	node2->next = NULL;
	node = node->next;
	while (node != NULL)
	{
		add_to_stack(node, &node2);
		node = node->next;
	}
	node2 = go_to_start(node2);
	return (node2);
}

void		ft_solve3(t_push **node1, t_push **node2, t_output **out, int iters)
{
	int		i;

	i = 0;
	while (i < iters)
	{
		mark_stack(node1, i, iters);
		*node2 = push_to_scnd_stack(node1, out, 0);
		sort_stacks(node1, node2, out);
		free_marks(node1);
		i++;
	}
}

void		ft_solve2(t_push **node1, t_push **node2, t_output **out)
{
	int		buf;
	int		swapper;

	buf = buf_sequence(*node1);
	swapper = leave_marks(node1, buf);
	*node2 = push_to_scnd_stack(node1, out, swapper);
	sort_stacks(node1, node2, out);
}

t_output	**best_solution(t_push **node1)
{
	t_push		*node2;
	t_push		*node1_2;
	t_push		*node1_3;
	t_output	**out;
	int			iterations;

	out = malloc(sizeof(t_output *) * 4);
	node1_2 = copy_stack(*node1);
	node1_3 = copy_stack(*node1);
	out[0] = allocate_output_struct(sizeof(t_output));
	out[1] = allocate_output_struct(sizeof(t_output));
	out[2] = allocate_output_struct(sizeof(t_output));
	ft_solve2(node1, &node2, &out[0]);
	iterations = 1;
	ft_solve3(&node1_2, &node2, &out[1], iterations);
	iterations = 3;
	ft_solve3(&node1_3, &node2, &out[2], iterations);
	free(node2);
	free_node(node1_2);
	free_node(node1_3);
	return (out);
}
