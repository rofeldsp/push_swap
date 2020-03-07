/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hexodecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:48:03 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/15 15:48:05 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_base2(int i, char **str)
{
	char	*str2;
	int		a;

	if ((str2 = ft_memalloc(i + 1)) == NULL)
		exit(-1);
	a = 0;
	i--;
	while (i >= 0)
		str2[a++] = *(*str + (i--));
	str2[a] = '\0';
	free(*str);
	return (str2);
}

char		*ft_itoa_base(__uint64_t nb, int base, char c)
{
	char	*str;
	int		i;
	char	*hex;

	if (c == 'F')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	i = 0;
	if ((str = ft_memalloc(60)) == NULL)
		exit(-1);
	while (nb / base != 0)
	{
		str[i++] = hex[nb % base];
		nb /= base;
	}
	str[i++] = hex[nb % base];
	str[i] = '\0';
	return (ft_itoa_base2(i, &str));
}

void		parse_hexodecimal3(t_print *node, char **str, char c)
{
	if (node->flag & OCTO && node->unumber != 0)
	{
		if (node->empty_space != 0 && node->precision > (int)ft_strlen(*str))
		{
			node->buffer[node->pointer - (node->precision - ft_strlen(*str))
																- 2] = '0';
			node->buffer[node->pointer - (node->precision - ft_strlen(*str))
												- 1] = (c == 'f' ? 'x' : 'X');
		}
		else
		{
			node->buffer[node->pointer++] = '0';
			node->buffer[node->pointer++] = (c == 'f' ? 'x' : 'X');
		}
	}
	*node = adjust_to_precision(*node, ft_strlen(*str), str);
}

void		parse_hexodecimal2(t_print *node, char c, char *str)
{
	int len;

	if (node->precision != -1)
		len = (node->flag & OCTO && node->unumber != 0 ? ft_strlen(str) + 2
				: ft_strlen(str));
	*node = adjust_to_width(*node, (node->precision == -1 ? 0 : len));
	*node = adjust_to_flag_v2(*node, (node->precision == -1 ? 0 : len), c, str);
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
	node->pointer += node->empty_space + (node->flag & OCTO && node->precision >
			0 && node->empty_space != 0 && node->unumber != 0 &&
			node->precision > (int)ft_strlen(str) ? 2 : 0);
}

t_print		parse_hexodecimal(t_print node, char c)
{
	char	*str;
	int		i;

	if (node.size & L)
		node.unumber = va_arg(node.ap, unsigned long int);
	else
		node.unumber = ((node.size & LL) ? va_arg(node.ap,
		unsigned long long int) : va_arg(node.ap, unsigned int));
	node.field_start = node.pointer;
	if (node.size & H)
		str = ft_itoa_base((unsigned short)node.unumber, 16, c);
	else
		str = (node.size & HH ? ft_itoa_base((unsigned char)node.unumber, 16, c)
				: ft_itoa_base(node.unumber, 16, c));
	i = 0;
	parse_hexodecimal2(&node, c, str);
	parse_hexodecimal3(&node, &str, c);
	while (str[i])
	{
		check_overflow(&node);
		node.buffer[node.pointer++] = str[i++];
	}
	node.input++;
	free(str);
	return (node);
}
