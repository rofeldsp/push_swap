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
		print_error(ERR_MALLOC);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
