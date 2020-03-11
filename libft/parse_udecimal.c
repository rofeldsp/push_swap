/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_udecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:57:25 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 10:57:27 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_udecimal2(t_print *node, char **str)
{
	int i;

	i = 0;
	*node = adjust_to_width(*node, (node->precision == -1 ? 0 :
	ft_strlen(*str)));
	*node = adjust_to_flag_v2(*node, (node->precision == -1 ? 0 :
	ft_strlen(*str)), '0', *str);
	node->pointer += node->empty_space;
	*node = adjust_to_precision_v3(*node, ft_strlen(*str), str);
	while ((*str)[i])
	{
		check_overflow(node);
		node->buffer[node->pointer++] = (*str)[i++];
	}
	node->input++;
	node->pointer = node->end_of_field > node->pointer ?
										node->end_of_field : node->pointer;
}

t_print		parse_udecimal(t_print node)
{
	char *str;

	if (node.size & L)
		node.unumber = va_arg(node.ap, unsigned long int);
	else
		node.unumber = (node.size & LL) ? va_arg(node.ap,
			unsigned long long int) : va_arg(node.ap, unsigned int);
	node.field_start = node.pointer;
	if (node.size & H)
		str = ft_uitoa((unsigned short)node.unumber);
	else
		str = (node.size == HH ? ft_uitoa((unsigned char)node.unumber) :
													ft_uitoa(node.unumber));
	parse_udecimal2(&node, &str);
	free(str);
	return (node);
}

static char	*cut(uint64_t j, uint64_t n)
{
	char			*dst;
	uint64_t		b;

	b = n;
	while (b / 10 > 0)
	{
		j++;
		b = b / 10;
	}
	if (!(dst = (char*)malloc(sizeof(char) * (j + 1))))
		exit(33);
	dst[j] = '\0';
	j--;
	while (n / 10 > 0)
	{
		dst[j] = '0' + n % 10;
		n = n / 10;
		j--;
	}
	dst[j] = '0' + n % 10;
	return (dst);
}

char		*ft_uitoa(uint64_t n)
{
	__uint64_t		j;
	char			*dst;

	j = 1;
	dst = cut(j, n);
	return (dst);
}
