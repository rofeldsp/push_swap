/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:38:49 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/15 18:38:54 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_decimal4(t_print *node, char **str)
{
	int		i;

	i = 0;
	while ((*str)[i])
	{
		check_overflow(node);
		node->buffer[node->pointer] = (*str)[i];
		i++;
		node->pointer++;
	}
	if (node->flag & MINUS)
	{
		if ((node->empty_space = (node->width > (int)ft_strlen(*str) ?
					node->width - ft_strlen(*str) : 0)) != 0)
			node->pointer += node->empty_space;
	}
	node->input++;
	free(*str);
}

void		parse_decimal3(t_print *node, char **str)
{
	if ((node->flag & SPACE) && (!(node->flag & PLUS)) && node->number >= 0)
	{
		if (node->pointer == node->field_start)
			node->buffer[node->pointer++] = ' ';
		else
		{
			if (node->flag & ZERO)
			{
				node->buffer[node->field_start] = ' ';
				node->empty_space = 0;
			}
			else
				node->buffer[node->pointer - 1] = ' ';
		}
	}
	*node = adjust_to_precision(*node, ft_strlen(*str), str);
	if (node->number < 0 && node->precision >= 0 && !(node->size & HH)
		&& !(node->size & H) && !(node->size & ZERO))
	{
		node->pointer_buf = node->pointer - 1;
		while (node->buffer[node->pointer_buf] != ' ' &&
				node->buffer[node->pointer_buf] != '\0')
			node->pointer_buf--;
		node->buffer[node->pointer_buf] = '-';
	}
}

void		parse_decimal2(t_print *node, char **str)
{
	*node = adjust_to_width(*node, (node->precision == -1 ? 0 :
	ft_strlen(*str)));
	*node = adjust_to_flag_v2(*node, (node->precision == -1 ? 0 :
	ft_strlen(*str)), '0', *str);
	if ((node->flag & ZERO && node->number < 0 && node->precision == -2))
	{
		node->buffer[node->field_start] = '-';
		*str = ft_strcpy(*str, &((*str)[1]));
		if (node->pointer == node->field_start)
			node->pointer++;
	}
	else if (node->number < 0 && node->precision >= 0 && !(node->size & HH)
							&& !(node->size & H))
	{
		*str = ft_strcpy(*str, &((*str)[1]));
		node->pointer++;
	}
	node->pointer += node->empty_space;
	node->pointer -= (node->empty_space != 0 && (node->flag & PLUS) != 0
						&& node->precision < 0) ? 1 : 0;
}

t_print		parse_decimal(t_print node)
{
	char	*str;

	if (node.size & L)
		node.number = va_arg(node.ap, long int);
	else
		node.number = ((node.size & LL) ? va_arg(node.ap, long long int)
				: va_arg(node.ap, int));
	node.field_start = node.pointer;
	if (node.size & H)
	{
		if (!(str = ft_itoa((short)node.number)))
			exit(-1);
	}
	else if (!(str = (node.size & HH) ? ft_itoa((char)node.number)
				: ft_itoa(node.number)))
		exit(-1);
	parse_decimal2(&node, &str);
	parse_decimal3(&node, &str);
	parse_decimal4(&node, &str);
	return (node);
}
