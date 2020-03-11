/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:15:44 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 12:15:46 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		parse_unicode(t_print node)
{
	unsigned int utf;

	utf = va_arg(node.ap, unsigned int);
	if (utf < 128)
		node.buffer[node.pointer++] = (char)utf;
	else if (utf < 2048)
	{
		node.buffer[node.pointer++] = (((utf >> 6) & 31) | 192);
		node.buffer[node.pointer++] = ((utf & 63) | 128);
	}
	else if (utf < 65536)
	{
		node.buffer[node.pointer++] = (((utf >> 6) & 15) | 224);
		node.buffer[node.pointer++] = (((utf >> 6) & 63) | 128);
		node.buffer[node.pointer++] = ((utf & 63) | 128);
	}
	else
	{
		node.buffer[node.pointer++] = (((utf >> 18) & 7) | 240);
		node.buffer[node.pointer++] = (((utf >> 12) & 63) | 128);
		node.buffer[node.pointer++] = (((utf >> 6) & 63) | 128);
		node.buffer[node.pointer++] = ((utf & 63) | 128);
	}
	node.input++;
	return (node);
}
