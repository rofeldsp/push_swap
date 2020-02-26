/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:11:55 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/20 14:11:57 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		addlist_to_output(t_output **out)
{
	if (*out == NULL)
		*out = allocate_output_struct(sizeof(t_output));
	else
	{
		(*out)->next = allocate_output_struct(sizeof(t_output));
		(*out)->next->prev = *out;
		*out = (*out)->next;
	}
}

t_push		*ft_swap_out(t_push *node, t_output **out, int stack_n)
{
	t_push *tmp;

	addlist_to_output(out);
	(*out)->oper = (stack_n == 1 ? SWAP_A : SWAP_B);
	tmp = node->next;
	node->next = node->next->next;
	tmp->next = node;
	tmp->prev = NULL;
	node->prev = tmp;
	return (tmp);
}

void		ft_push_out(t_push **node1, t_push **node2, t_output **out, int s_n)
{
	t_push *tmp;

	addlist_to_output(out);
	(*out)->oper = (s_n == 1 ? PUSH_A : PUSH_B);
	tmp = (*node1)->next;
	if ((*node2)->nbr == EMPTY_NODE)
	{
		*node2 = *node1;
		(*node2)->next = NULL;
		(*node2)->prev = NULL;
	}
	else
	{
		(*node1)->next = *node2;
		(*node2)->prev = *node1;
		*node2 = *node1;
	}
	*node1 = tmp;
	if (*node1 != NULL)
		(*node1)->prev = NULL;
//	t_push *tmp1;
//
//	tmp1 = allocate_struct(sizeof(t_push));
//	*tmp1 = **node1;
//	tmp1->prev = NULL;
//	if ((*node2)->nbr == EMPTY_NODE)
//	{
//		tmp1->next = NULL;
//		*node2 = tmp1;
//	}
//	else
//	{
//		tmp1->next = *node2;
//		(*node2)->prev = tmp1;
//		*node2 = tmp1;
//	}
//	*node1 = (*node1)->next;
//	(*node1)->prev = NULL;
//	free(tmp1);
}

t_push		*ft_rotate_out(t_push *node, t_output **out, int stack_n)
{
	t_push	*tmp;
	t_push	*head;

	addlist_to_output(out);
	(*out)->oper = (stack_n == 1 ? ROT_A : ROT_B);
	head = node->next;
	tmp = node->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
	node->prev = tmp;
	head->prev = NULL;
	return (head);
}

t_push		*ft_reverse_out(t_push *node, t_output **out, int stack_n)
{
	t_push	*tmp;

	addlist_to_output(out);
	(*out)->oper = (stack_n == 1 ? RROT_A : RROT_B);
	while (node->next != NULL)
		node = node->next;
	tmp = node;
	if (node->prev != NULL)
	{
		node = node->prev;
		node->next = NULL;
		while (node->prev != NULL)
			node = node->prev;
		node->prev = tmp;
		node->prev->next = node;
		node = node->prev;
		node->prev =  NULL;
	}
	return (node);
}
