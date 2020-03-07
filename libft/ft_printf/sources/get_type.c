/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:51:02 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/15 14:51:04 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		get_type(t_print node)
{
	if (*node.input == 'c')
		return (parse_char(node));
	else if (*node.input == 's')
		return (parse_string(node));
	else if (*node.input == 'd' || *node.input == 'i')
		return (node.size & UNIC ? parse_unicode(node) : parse_decimal(node));
	else if (*node.input == 'u')
		return (parse_udecimal(node));
	else if (*node.input == '%')
		return (parse_percent(node));
	else if (*node.input == 'x' || *node.input == 'X')
		return (parse_hexodecimal(node, (*node.input == 'x' ? 'f' : 'F')));
	else if (*node.input == 'b')
		return (parse_binary(node));
	else if (*node.input == 'o')
		return (parse_octal(node, 'a'));
	else if (*node.input == 'p')
		return (parse_pointer(node));
	else if (*node.input == 'f')
	{
		node.fnumber = (node.size & FLOAT_L ?
		va_arg(node.ap, long double) : va_arg(node.ap, double));
		return (parse_float(node));
	}
	return (node);
}
