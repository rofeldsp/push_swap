/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:38:53 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/03/09 13:38:54 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		create_node2(t_push **node2)
{
	if (*node2 == NULL)
	{
		*node2 = allocate_struct(sizeof(t_push));
		(*node2)->nbr = EMPTY_NODE;
	}
}
