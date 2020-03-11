/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:41:59 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 11:42:00 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		parse_percent(t_print node)
{
	char *str;

	str = "\0";
	node = adjust_to_width(node, 1);
	node = adjust_to_flag_v2(node, 1, '0', str);
	node.pointer += node.empty_space;
	node = adjust_to_precision(node, 1, &str);
	check_overflow(&node);
	node.buffer[node.pointer++] = '%';
	node.input++;
	return (node);
}
