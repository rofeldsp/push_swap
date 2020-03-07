/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:24:19 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 11:24:21 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_pointer2(t_print *node, char **str)
{
	int		i;

	i = 0;
	if (node->empty_space != 0)
		node->pointer += node->empty_space - 2;
	node->buffer[node->pointer++] = '0';
	node->buffer[node->pointer++] = 'x';
	*node = adjust_to_precision_v3(*node, ft_strlen(*str), str);
	while ((*str)[i])
	{
		check_overflow(node);
		node->buffer[node->pointer++] = (*str)[i++];
	}
	if (node->flag & MINUS)
	{
		if ((node->empty_space = (node->width > (int)ft_strlen(*str) + 2 ?
							node->width - ft_strlen(*str) - 2 : 0)) != 0)
			node->pointer += node->empty_space;
	}
}

t_print		parse_pointer(t_print node)
{
	void	*pointer;
	char	*str;
	int		len;

	pointer = va_arg(node.ap, void *);
	str = ft_itoa_base((uint64_t)pointer, 16, 'a');
	if (node.precision == -1)
		len = 0;
	else
		len = node.flag & OCTO ? ft_strlen(str) + 2 : ft_strlen(str);
	node = adjust_to_width(node, len);
	node = adjust_to_flag_v2(node, len, 'a', str);
	parse_pointer2(&node, &str);
	node.input++;
	free(str);
	return (node);
}
