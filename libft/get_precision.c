/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:26:58 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/15 14:27:01 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		get_precision2(t_print node)
{
	if (*node.input < '0' || *node.input > '9')
	{
		node.precision = -1;
		if (*node.input == '0')
			node.input++;
		node = get_size(node);
		node.return_status = 1;
		return (node);
	}
	node.precision = *node.input - '0';
	node.input++;
	while (*node.input >= '0' && *node.input <= '9')
	{
		node.precision = node.precision * 10 + (*node.input - '0');
		node.input++;
	}
	return (node);
}

t_print		get_precision(t_print node)
{
	int i;

	i = 0;
	if (*node.input == '.')
	{
		node.input++;
		while (i++ == 0 || ((*node.input >= '0' && *node.input <= '9') ||
				*node.input == '*'))
			if (*node.input == '*')
			{
				node.precision = va_arg(node.ap, int);
				if (node.precision < 0)
					node.precision = -2;
				node.input++;
			}
			else
			{
				node = get_precision2(node);
				if (node.return_status == 1)
					return (node);
			}
		if (node.precision == 0)
			node.precision = -1;
	}
	return (get_size(node));
}
