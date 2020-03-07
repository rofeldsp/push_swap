/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:07:24 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 14:07:25 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_float8(t_print *node, __int64_t *num, char **str)
{
	if (node->flag & ZERO && !(node->flag & MINUS))
	{
		if (*num < 0 || node->flag & PLUS)
		{
			node->buffer[node->field_start] = *num < 0 ? '-' : '+';
			*str = ft_strcpy(*str, &((*str)[*num < 0 ? 1 : 0]));
			node->empty_space -= *num < 0 ? 0 : 1;
			node->pointer += *num < 0 ? 1 : 0;
			node->field_start++;
		}
		while (node->field_start < node->pointer)
			node->buffer[node->field_start++] = '0';
	}
}

void		parse_float7(t_print *node, __int64_t *num, char **str)
{
	if (node->flag & PLUS && *num >= 0)
	{
		if (node->flag & ZERO && node->width > (int)ft_strlen(*str))
		{
			if (node->pointer == node->field_start)
				node->buffer[node->pointer++] = '+';
			else
				node->buffer[node->field_start] = '+';
		}
		else
			node->buffer[node->pointer > node->field_start ? node->pointer - 1
										: node->pointer++] = '+';
	}
	if (node->flag & MINUS)
		node->pointer = node->field_start + node->flag & PLUS
						&& *num >= 0 ? 1 : 0;
}

void		parse_float6(t_print *node, __int64_t *num)
{
	if ((node->flag & SPACE) && (!(node->flag & PLUS)) && *num >= 0)
	{
		if (node->pointer == node->field_start)
		{
			node->buffer[node->pointer++] = ' ';
			node->field_start++;
		}
		else
		{
			if (node->flag & ZERO)
			{
				node->buffer[node->field_start] = ' ';
				node->empty_space = 0;
				node->field_start++;
			}
			else
				node->buffer[node->pointer - 1] = ' ';
		}
	}
}

void		parse_float5(t_print *node, __int64_t *num, char **str)
{
	if ((node->flag & ZERO && *num < 0 && node->precision == -2))
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
}

void		parse_float4(t_print *node, char **tmp, char **str, char **str2)
{
	if (node->precision > 0 || (node->flag & OCTO))
	{
		if (!(*tmp = ft_strjoin(*str, ".")))
			exit(-1);
		free(*str);
		if (!(*str = ft_strjoin(*tmp, *str2)))
			exit(-1);
		free(*tmp);
		free(*str2);
	}
}
