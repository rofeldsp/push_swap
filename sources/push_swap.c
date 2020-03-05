/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:24:07 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/19 13:24:10 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	char *str;
	t_push *node;

	if (argc == 1)
	{
		print_error();
		exit(33); // почему без этого не компилится?
	}
	else
		str = parse_input(argc, argv);
	node = parse_stack(str);
	ft_solve(&node);
//	free_node(node);
	free (str);
	return (0);
}
