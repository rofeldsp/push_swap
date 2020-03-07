/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:55:32 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 11:55:33 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		adjust_to_precision_3(t_print *node, int len)
{
	if (node->flag & PLUS)
	{
		if (node->number >= 0)
		{
			if (node->flag & ZERO && node->width > len)
			{
				if (node->pointer == node->field_start)
					node->buffer[node->pointer++] = '+';
				else
					node->buffer[node->field_start] = '+';
			}
			else
				node->buffer[node->pointer++] = '+';
		}
	}
	if (node->pointer != node->field_start &&
										node->buffer[node->pointer - 1] == '\0')
		node->buffer[node->pointer - 1] = ' ';
	while ((node->precision--) - len > 0)
	{
		check_overflow(node);
		node->buffer[node->pointer++] = '0';
	}
}

void		adjust_to_precision_2(t_print *node, int len)
{
	int		pointer_buff;

	pointer_buff = node->pointer;
	while ((node->precision--) - len > 0)
	{
		check_overflow(node);
		node->buffer[--node->pointer] = '0';
	}
	if (node->flag & PLUS)
	{
		if (node->number >= 0)
		{
			if (node->pointer == node->field_start)
				node->buffer[pointer_buff++] = '+';
			else
				node->buffer[--node->pointer] = '+';
		}
	}
	node->pointer = pointer_buff;
}

t_print		adjust_to_precision(t_print node, int len, char **str)
{
	if (node.precision == -1 && (node.unumber == 0 || node.number == 0))
		*(str[0]) = '\0';
	if (node.precision < node.width && ((node.flag & MINUS) != MINUS) &&
													node.precision >= 0)
		adjust_to_precision_2(&node, len);
	else
		adjust_to_precision_3(&node, len);
	return (node);
}
