/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:20:00 by rofeldsp          #+#    #+#             */
/*   Updated: 2019/12/26 17:20:02 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	t_print		node;

	if (str == NULL)
		exit(33);
	node.pointer = 0;
	node.count_nulls = 0;
	node.buffer_size = BUFF_SIZE;
	if (!(node.buffer = ft_strnew(node.buffer_size)))
		exit(-1);
	va_start(node.ap, str);
	node.input = (char *)str;
	while (*node.input)
	{
		check_overflow(&node);
		if (*node.input == '%')
			node = print_arg(node);
		else if (*node.input != '{')
			node.buffer[node.pointer++] = *(node.input++);
		if (*node.input == '{')
			node = print_color(node);
	}
	va_end(node.ap);
	node.pointer = ft_putstr_printf(node.buffer, node.count_nulls);
	free(node.buffer);
	return (node.pointer);
}

int			ft_dprintf(int fd, const char *str, ...)
{
	t_print		node;

	node.pointer = 0;
	node.count_nulls = 0;
	node.buffer_size = BUFF_SIZE;
	if (!(node.buffer = ft_strnew(node.buffer_size)))
		exit(-1);
	va_start(node.ap, str);
	node.input = (char *)str;
	while (*node.input)
	{
		check_overflow(&node);
		if (*node.input == '%')
			node = print_arg(node);
		else if (*node.input != '{')
			node.buffer[node.pointer++] = *(node.input++);
		if (*node.input == '{')
			node = print_color(node);
	}
	va_end(node.ap);
	node.pointer = ft_putstr_dprintf(fd, node.buffer, node.count_nulls);
	free(node.buffer);
	return (node.pointer);
}
