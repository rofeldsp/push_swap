/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_to_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:54:49 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 13:54:51 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		adjust_to_flag(t_print node, int len)
{
	int	len_width;

	node.empty_space = (node.width > len) ? node.width - len : 0;
	len_width = node.empty_space;
	if (node.flag & MINUS)
		node.empty_space = 0;
	if (node.flag & ZERO)
		while (len_width-- > 0)
		{
			check_overflow(&node);
			node.buffer[node.pointer++] = '0';
		}
	return (node);
}

t_print		adjust_to_flag_v2(t_print node, int len, char c, char *str)
{
	int	len_width;

	node.empty_space = (node.width > len) ? node.width - len : 0;
	if (node.flag & MINUS)
		node.empty_space = 0;
	len_width = node.empty_space;
	if (str[0] == '-')
		len_width++;
	if (node.flag & ZERO && node.precision < 0)
	{
		if (node.flag & OCTO && node.unumber != 0 && (c == 'F' || c == 'f'))
		{
			node.buffer[node.pointer++] = '0';
			node.buffer[node.pointer++] = (c == 'F' ? 'X' : 'x');
			node.flag ^= OCTO;
		}
		while (len_width-- > 0)
		{
			check_overflow(&node);
			node.buffer[node.pointer++] = '0';
		}
		node.empty_space = 0;
	}
	return (node);
}

t_print		adjust_to_flag_v3(t_print node, int len, char *str)
{
	int	len_width;

	node.empty_space = (node.width > len) ? node.width - len : 0;
	if (node.flag & MINUS)
		node.empty_space = 0;
	len_width = node.empty_space;
	if (str[0] == '-')
	{
		len_width++;
	}
	return (node);
}
