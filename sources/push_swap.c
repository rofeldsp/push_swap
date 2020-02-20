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

void free_node(t_push *node)
{
	t_push *tmp;

	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}

}

int main(int argc, char **argv)
{
	char *str;
	t_push *node;
	t_push *node2;

	node2 = malloc(sizeof(t_push));
	node2->next = NULL;
	node2->prev = NULL;
	node2->nbr = 5;
	if (argc == 1)
		print_error(ERR_ARG);
	else
		str = parse_string(argc, argv);
	node = parse_stack(str);
	ft_push(node, node2);
	free_node(node);
	free (str);
	return (0);
}
