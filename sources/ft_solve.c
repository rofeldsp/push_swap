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

/*
** Function responsible for finding solution. We use swapper in different
** situations, because of 5 variable limitation of ecole 42.
*/

void	ft_solve(t_push **node1, int *fd)
{
	t_push		*node2;
	t_output	*out;
	int			iterations;

	if (best_sequence(*node1) == stack_length(*node1))
		return ;
	out = allocate_output_struct(sizeof(t_output));
	if (stack_length(*node1) <= 50)
		ft_solve2(node1, &node2, &out);
	else if (stack_length(*node1) <= 200)
	{
		iterations = 1;
		ft_solve3(node1, &node2, &out, iterations);
	}
	else
	{
		iterations = 3;
		ft_solve3(node1, &node2, &out, iterations);
	}
	while (out->prev != NULL)
		out = out->prev;
	out = combine_rotations(&out);
	display_output(out, (*node1)->debug_opt, fd);
	free_output(out);
	free(node2);
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
