/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:52:10 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 13:52:11 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		adjust_to_width(t_print node, int len)
{
	int len2;

	if (node.width == -1 || node.precision > node.width)
		node.width = len;
	len2 = node.width;
	node.end_of_field = node.pointer + node.width;
	if (node.width <= len)
		return (node);
	while (len2 > 0)
	{
		check_overflow(&node);
		node.buffer[node.pointer + node.width - len2] = ' ';
		len2--;
	}
	return (node);
}

t_print		adjust_to_width2(t_print node, int len)
{
	int len2;
	int width_buf;

	width_buf = node.width;
	if (node.width == -1)
		node.width = len;
	len2 = node.width;
	node.end_of_field = node.pointer + node.width;
	if (width_buf <= 0)
		return (node);
	while (len2 > 0)
	{
		check_overflow(&node);
		node.buffer[node.pointer + node.width - len2] = ' ';
		len2--;
	}
	return (node);
}
