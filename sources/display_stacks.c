/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:07:45 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/03/05 15:07:46 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stacks_in_color(t_push *n1, t_push *n2)
{
	ft_printf("{yellow}---------{red}Stack A{yellow}---------||---------{red}Stack B{yellow}---------\n");
//	ft_putstr("---------Stack A---------||---------Stack B---------\n");
	while (n1 != NULL || n2 != NULL)
	{
		if (n1 == NULL || n1->nbr == EMPTY_NODE)
			ft_printf("|{cyan}%24c{yellow}||{blue}%24d{yellow}|\n", ' ', n2->nbr);
		else if (n2 == NULL || n2->nbr == EMPTY_NODE)
			ft_printf("|{cyan}%-24d{yellow}||{blue}%24c{yellow}|\n", n1->nbr, ' ');
		else
			ft_printf("|{cyan}%-24d{yellow}||{blue}%24d{yellow}|\n", n1->nbr, n2->nbr);
		if (n1 != NULL)
			n1 = n1->next;
		if (n2 != NULL)
			n2 = n2->next;
	}
	ft_printf("----------------------------------------------------\n{eoc}");

}

void	display_stacks(t_push *node1, t_push *node2, int stack_n)
{
	t_push	*n1;
	t_push	*n2;

	n1 = stack_n == 2 ? node2 : node1;
	n2 = stack_n == 2 ? node1 : node2;
	if ((n1 != NULL && n1->debug_opt & COLOR) || (n2 != NULL && n2->debug_opt & COLOR))
		display_stacks_in_color(n1, n2);
	else
	{
		ft_putstr("---------Stack A---------||---------Stack B---------\n");
		while (n1 != NULL || n2 != NULL)
		{
			if (n1 == NULL || n1->nbr == EMPTY_NODE)
				ft_printf("|%24c||%24d|\n", ' ', n2->nbr);
			else if (n2 == NULL || n2->nbr == EMPTY_NODE)
				ft_printf("|%-24d||%24c|\n", n1->nbr, ' ');
			else
				ft_printf("|%-24d||%24d|\n", n1->nbr, n2->nbr);
			if (n1 != NULL)
				n1 = n1->next;
			if (n2 != NULL)
				n2 = n2->next;
		}
		ft_putstr("----------------------------------------------------\n");
	}
}
