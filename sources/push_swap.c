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

int		main(int argc, char **argv)
{
	char		*str;
	t_push		*node;
	int			fd;

	fd = 1;
	if (argc == 1)
		print_error();
	str = parse_input(argc, argv);
	if (!(node = parse_stack(str)))
		print_error();
	ft_solve(&node, &fd);
	if (fd > 2)
		close(fd);
	free_node(node);
	free(str);
	return (0);
}
