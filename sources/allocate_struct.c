/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:30:39 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/21 15:30:43 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push		*allocate_struct(size_t size)
{
	t_push *node;

	if (!(node = malloc(size)))
		print_error();
	node->next = NULL;
	node->prev = NULL;
	node->debug_opt = 0;
	node->marker = 0;
	return (node);
}

t_output	*allocate_output_struct(size_t size)
{
	t_output *node;

	if (!(node = malloc(size)))
		print_error();
	node->next = NULL;
	node->prev = NULL;
	node->oper = 0;
	return (node);
}
