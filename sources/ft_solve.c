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

int		is_sorted(t_push *node1)
{
	int		num;

	num = node1->nbr;
	node1 = node1->next;
	while (node1 != NULL)
	{
		if (node1->nbr < num)
			return (0);
		else
			node1 = node1->next;
	}
	return (1);
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
	t_output	**out;

	if (best_sequence(*node1) == stack_length(*node1) && is_sorted(*node1))
		return ;
	out = best_solution(node1);
	while (out[0]->prev != NULL)
		out[0] = out[0]->prev;
	while (out[1]->prev != NULL)
		out[1] = out[1]->prev;
	while (out[2]->prev != NULL)
		out[2] = out[2]->prev;
	out[0] = combine_rotations(&out[0]);
	out[1] = combine_rotations(&out[1]);
	out[2] = combine_rotations(&out[2]);
	out[3] = stack_length2(out[0]) > stack_length2(out[1]) ? out[1] : out[0];
	out[3] = stack_length2(out[3]) > stack_length2(out[2]) ? out[2] : out[3];
	display_output(out[3], (*node1)->debug_opt, fd);
	free_output(out[0]);
	free_output(out[1]);
	free_output(out[2]);
	free(out);
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
