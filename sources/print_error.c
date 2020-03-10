/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:48:08 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/19 13:48:10 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_fd(void)
{
	write(2, "Failed to open file\n", 20);
	exit(1);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
