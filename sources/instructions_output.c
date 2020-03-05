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

t_output 		*addlist_to_output(t_output **out)
{
	if ((*out)->oper == 0)
		return (*out);
//		*out = allocate_output_struct(sizeof(t_output));
	else
	{
		(*out)->next = allocate_output_struct(sizeof(t_output));
		(*out)->next->prev = *out;
		*out = (*out)->next;
	}
	return (*out);
}

t_push		*ft_swap_out(t_push *node, t_push *node2, t_output **out, int stack_n)
{
	t_push *tmp;

	if (node->next == NULL)
		return (node);
	*out = addlist_to_output(out);
	(*out)->oper |= (stack_n == 1 ? SWAP_A : SWAP_B);
	tmp = node->next;
	node->next = node->next->next;
	tmp->next = node;
	tmp->prev = NULL;
	node->prev = tmp;
	if (node->debug_opt & DEBUG)
		display_stacks(tmp, node2, stack_n);
	return (tmp);
}

void		ft_push_out(t_push **node1, t_push **node2, t_output **out, int s_n)
{
	t_push *tmp;

	*out = addlist_to_output(out);
	(*out)->oper |= (s_n == 1 ? PUSH_B : PUSH_A);
	tmp = (*node1)->next;
	if ((*node2)->nbr == EMPTY_NODE)
	{
		free(*node2);
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
	if ((*node1 != NULL && (*node1)->debug_opt & DEBUG) || (*node2 != NULL
											&& (*node2)->debug_opt & DEBUG))
		display_stacks(*node1, *node2, s_n);
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

t_push		*ft_rotate_out(t_push *node, t_push *node2, t_output **out, int stack_n)
{
	t_push	*tmp;
	t_push	*head;

	if (node->next == NULL)
		return (node);
	*out = addlist_to_output(out);
	(*out)->oper |= (stack_n == 1 ? ROT_A : ROT_B);
	head = node->next;
	tmp = node->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
	node->prev = tmp;
	head->prev = NULL;
	if (node->debug_opt & DEBUG)
		display_stacks(head, node2, stack_n);
	return (head);
}

t_push		*ft_reverse_out(t_push *node, t_push *node2, t_output **out, int stack_n)
{
	t_push	*tmp;

	if (node->next == NULL)
		return (node);
	*out = addlist_to_output(out);
	(*out)->oper |= (stack_n == 1 ? RROT_A : RROT_B);
	while (node->next != NULL)
		node = node->next;
	tmp = node;
	node = node->prev;
	node->next = NULL;
	while (node->prev != NULL)
		node = node->prev;
	node->prev = tmp;
	node->prev->next = node;
	node = node->prev;
	node->prev =  NULL;
	if (node->debug_opt & DEBUG) // change to &
		display_stacks(node, node2, stack_n);
	return (node);
}
