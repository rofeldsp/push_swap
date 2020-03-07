/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:39:50 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/15 14:39:52 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_size2(t_print *node)
{
	if (*node->input == 'l')
	{
		if (*(node->input + 1) == 'l')
		{
			node->size |= LL;
			node->input++;
		}
		else
			node->size |= L;
	}
	if (*node->input == 'h')
	{
		if (*(node->input + 1) == 'h')
		{
			node->size |= HH;
			node->input++;
		}
		else
			node->size |= H;
	}
	node->input++;
}

t_print		get_size(t_print node)
{
	node.size = 0;
	if (*node.input == 'l' || *node.input == 'h')
		get_size2(&node);
	else if (*node.input == 'L' || *node.input == 'U')
	{
		node.size |= (*node.input == 'L' ? FLOAT_L : UNIC);
		node.input++;
	}
	return (get_type(node));
}
