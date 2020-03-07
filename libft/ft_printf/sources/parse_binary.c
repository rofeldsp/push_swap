/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:01:24 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/15 15:01:26 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_bits(void *nbr, int size, t_print *node)
{
	unsigned char	*c;
	int				bit;

	c = (unsigned char *)nbr + size;
	while (--c >= (unsigned char *)nbr)
	{
		bit = 128;
		check_overflow(node);
		while (bit >= 1)
		{
			node->buffer[node->pointer] = '0';
			if (*c & bit)
				node->buffer[node->pointer] = '1';
			node->pointer++;
			if ((bit >>= 1) == 8 || (bit == 0 && c != (unsigned char *)nbr))
				node->buffer[node->pointer++] = ' ';
		}
	}
	node->input += (*(node->input + 1) == 'f' ? 2 : 1);
}

t_print		parse_binary(t_print node)
{
	long double a;
	double		c;
	int64_t		b;

	if ((*node.input + 1) == 'f')
		a = va_arg(node.ap, long double);
	else
		b = va_arg(node.ap, int64_t);
	if ((*node.input + 1) == 'f' && node.size & FLOAT_L)
		parse_bits(&a, 10, &node);
	else if ((*node.input + 1) == 'f')
	{
		c = (double)a;
		parse_bits(&c, sizeof(double), &node);
	}
	else if (node.size & H)
		parse_bits(&b, sizeof(short), &node);
	else if (node.size & HH)
		parse_bits(&b, sizeof(char), &node);
	else if (node.size & L || node.size & LL)
		parse_bits(&b, sizeof(int64_t), &node);
	else
		parse_bits(&b, sizeof(int), &node);
	return (node);
}
