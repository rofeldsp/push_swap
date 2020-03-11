/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:46 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 11:43:47 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_string2(t_print *node, char **str)
{
	int		i;

	i = 0;
	if (node->empty_space > 0)
		node->pointer += node->empty_space;
	else
		node->pointer += (node->width > node->precision && node->precision >= 0
				&& node->width != (int)ft_strlen(*str) && node->flag ^ MINUS) ?
											node->width - node->precision : 0;
	adjust_to_precision_v2(node, str);
	while ((*str)[i])
	{
		check_overflow(node);
		node->buffer[node->pointer++] = (*str)[i++];
	}
	node->input++;
	if (node->flag & MINUS)
		node->pointer = node->end_of_field;
}

t_print		parse_string(t_print node)
{
	char	*str;

	str = va_arg(node.ap, char *);
	if (str == NULL)
		str = "(null)";
	node = adjust_to_width2(node, ft_strlen(str));
	node = adjust_to_flag(node, ft_strlen(str));
	parse_string2(&node, &str);
	free(str);
	return (node);
}
