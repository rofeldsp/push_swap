/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:55:03 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/03/03 16:55:04 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_node(t_push *node)
{
	t_push *tmp;

	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

void		free_output(t_output *node)
{
	t_output *tmp;

	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

t_output 	*delete_node(t_output **out)
{
	t_output	*nex;

	nex = (*out)->next;
	(*out)->prev->next = (*out)->next;
	(*out)->next->prev = (*out)->prev;
	free(*out);
	return (nex);
}

void 		free_marks(t_push **node1)
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
