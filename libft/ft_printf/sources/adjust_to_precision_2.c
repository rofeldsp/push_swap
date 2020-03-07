/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_to_precision_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:04:03 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 14:04:04 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		adjust_to_precision_v2_2(t_print *node, char **str, char **str2)
{
	if (ft_strlen(*str) != ft_strlen(*str2) && node->width >
				(int)ft_strlen(*str) && node->flag ^ MINUS)
		node->pointer += ft_strlen(*str) - ft_strlen(*str2);
	if (node->width == (int)ft_strlen(*str))
		node->end_of_field -= (ft_strlen(*str) - ft_strlen(*str2));
	if (!(*str = ft_strdup(*str2)))
		exit(-1);
}

void		adjust_to_precision_v2(t_print *node, char **str)
{
	int		len;
	char	*str2;

	if (node->precision > -2)
	{
		len = ft_strlen(*str);
		if (!(str2 = ft_strdup(*str)))
			exit(-1);
		if (node->precision == -1)
		{
			str2[0] = '\0';
			if (!(*str = ft_strdup(str2)))
				exit(-1);
			free(str2);
			return ;
		}
		while (len > node->precision && len - 1 >= 0)
			str2[--len] = '\0';
		adjust_to_precision_v2_2(node, str, &str2);
		free(str2);
	}
	else if (!(*str = ft_strdup(*str)))
		exit(-1);
}

void		adjust_to_precision_v3_2(t_print *node, int len)
{
	int pointer_buff;

	pointer_buff = node->pointer;
	while ((node->precision--) - len > 0)
	{
		if ((node->pointer + 1) % BUFF_SIZE == 1)
			node->buffer = increase_buffer(&node->buffer, node);
		node->buffer[--node->pointer] = '0';
	}
	node->pointer = pointer_buff;
}

t_print		adjust_to_precision_v3(t_print node, int len, char **str)
{
	if (node.precision == -1 && ((node.unumber == 0 || node.number == 0) ||
							(node.number == 1 && node.unumber == 1)))
		(*str)[0] = '\0';
	if (node.precision < node.width && ((node.flag & MINUS) != MINUS) &&
		node.precision >= 0)
		adjust_to_precision_v3_2(&node, len);
	else
	{
		while ((node.precision--) - len > 0)
		{
			check_overflow(&node);
			node.buffer[node.pointer++] = '0';
		}
	}
	return (node);
}
