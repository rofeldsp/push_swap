/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:15:31 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 12:15:32 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_octal3(t_print *node, char **str)
{
	int		i;

	i = 0;
	if (node->flag & OCTO)
	{
		node->buffer[node->unumber == 0 && node->width >
		(int)ft_strlen(*str) + 1 && !(node->flag & MINUS) ?
						node->pointer++ + 1 : node->pointer++] = '0';
		if ((node->precision > 0 && node->pointer == node->field_start + 1) ||
															node->unumber == 0)
			node->precision--;
		if ((*str)[i] == '0')
			(*str)[i] = '\0';
	}
	*node = adjust_to_precision(*node, ft_strlen(*str), str);
	while ((*str)[i])
	{
		check_overflow(node);
		node->buffer[node->pointer++] = (*str)[i++];
	}
	node->input++;
	if (node->buffer[node->pointer] != '\0')
		node->pointer++;
}

void		parse_octal2(t_print *node, char **str, char c)
{
	int len;

	if (node->precision == -1)
		len = 0;
	else
		len = node->flag & OCTO ? ft_strlen(*str) + 1 : ft_strlen(*str);
	*node = adjust_to_width(*node, len);
	*node = adjust_to_flag_v2(*node, (node->flag & OCTO ? ft_strlen(*str) + 1
	: ft_strlen(*str)), c, *str);
	if ((node->flag & SPACE) && (!(node->flag & PLUS)) && node->number >= 0)
	{
		check_overflow(node);
		if (node->flag & ZERO)
		{
			node->buffer[node->pointer - node->empty_space] = ' ';
			node->empty_space = 0;
		}
		else
			node->buffer[node->pointer++] = ' ';
	}
	node->pointer += node->empty_space;
	if (node->unumber == 0 && node->width > (int)ft_strlen(*str) + 1 &&
		!(node->flag & MINUS) && (node->flag & ZERO) && (*str)[0] == '0')
		node->buffer[node->pointer] = '0';
}

t_print		parse_octal(t_print node, char c)
{
	char	*str;

	if (node.size & L)
		node.unumber = va_arg(node.ap, unsigned long int);
	else
		node.unumber = (node.size & LL) ? va_arg(node.ap,
			unsigned long long int) : va_arg(node.ap, unsigned int);
	node.field_start = node.pointer;
	if (node.size & H)
		str = ft_itoa_base((unsigned short)node.unumber, 8, c);
	else
		str = (node.size & HH ? ft_itoa_base((unsigned char)node.unumber, 8, c)
						: ft_itoa_base(node.unumber, 8, 'a'));
	parse_octal2(&node, &str, c);
	parse_octal3(&node, &str);
	free(str);
	return (node);
}
