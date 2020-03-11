/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:26:23 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/15 14:26:26 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		get_flag(t_print node)
{
	while (1)
	{
		if (*node.input == '-')
			node.flag |= MINUS;
		else if (*node.input == '+')
			node.flag |= PLUS;
		else if (*node.input == ' ')
			node.flag |= SPACE;
		else if (*node.input == '0')
			node.flag |= ZERO;
		else if (*node.input == '#')
			node.flag |= OCTO;
		else
			return (get_width(node));
		node.input++;
	}
}
