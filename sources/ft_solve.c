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

void	ft_solve3(t_push **node1, t_push **node2, t_output **out, int iters)
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

void	ft_solve2(t_push **node1, t_push **node2, t_output **out)
{
	int		buf;
	int		swapper;

	buf = buf_sequence(*node1);
	swapper = leave_marks(node1, buf);
	*node2 = push_to_scnd_stack(node1, out, swapper);
	sort_stacks(node1, node2, out);
}

void	add_to_stack(t_push *node, t_push **node2)
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

t_push *copy_stack(t_push *node)
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
	return(node2);
}

int		stack_length2(t_output *node)
{
	int i;

	if (node == NULL)
		return (0);
	else
		i = 1;
	while (node->next != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

/*
** Function responsible for finding solution. We use swapper in different
** situations, because of 5 variable limitation of ecole 42.
*/

void	ft_solve(t_push **node1, int *fd)
{
	t_push		*node2;
	t_push		*node1_2;
	t_push		*node1_3;
	t_output	*out;
	t_output	*out2;
	t_output	*out3;
	t_output	*out4;
	int			iterations;

	node1_2 = copy_stack(*node1);
	node1_3 = copy_stack(*node1);
	if (best_sequence(*node1) == stack_length(*node1))
		return ;
	out = allocate_output_struct(sizeof(t_output));
	out2 = allocate_output_struct(sizeof(t_output));
	out3 = allocate_output_struct(sizeof(t_output));
//	if (stack_length(*node1) <= 50)
	ft_solve2(node1, &node2, &out);
//	else if (stack_length(*node1) <= 200)
//	{
//	out2 = allocate_output_struct(sizeof(t_output));
//	if (stack_length(*node1) <= 50)
		ft_solve2(node1, &node2, &out);
//	else if (stack_length(*node1) <= 200)
//	{
		iterations = 1;
		ft_solve3(&node1_2, &node2, &out2, iterations);
//	}
//	else
//	{
		iterations = 3;
		ft_solve3(&node1_3, &node2, &out3, iterations);
//	}
	while (out->prev != NULL)
		out = out->prev;
	while (out2->prev != NULL)
		out2 = out2->prev;
	while (out3->prev != NULL)
		out3 = out3->prev;
	out = combine_rotations(&out);
	out2 = combine_rotations(&out2);
	out3 = combine_rotations(&out3);
	out4 = stack_length2(out) > stack_length2(out2) ? out2 : out;
	out4 = stack_length2(out4) > stack_length2(out3) ? out3 : out4;
	display_output(out4, (*node1)->debug_opt, fd);
	free_output(out);
	free_output(out2);
	free_output(out3);
	free(node2);
	free_node(node1_2);
	free_node(node1_3);
}


int		stack_length(t_push *node)
{
	int i;

	if (node == NULL)
		return (0);
	else
		i = 1;
	while (node->next != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}
