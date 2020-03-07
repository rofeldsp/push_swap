/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:25:52 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/15 14:25:56 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_printf(char *str, int a)
{
	int i;

	i = 0;
	while (str[i] || a > 0)
	{
		if (str[i] == '\0')
			a--;
		ft_putchar(str[i++]);
	}
	return (i);
}

int		ft_putstr_dprintf(int fd, char *str, int a)
{
	int i;

	i = 0;
	while (str[i] || a > 0)
	{
		if (str[i] == '\0')
			a--;
		write(fd, &(str[i++]), 1);
	}
	return (i);
}
