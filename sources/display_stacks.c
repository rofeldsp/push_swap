//
// Created by Igor Krasnov on 05.03.20.
//

#include "push_swap.h"

void	display_stacks(t_push *node1, t_push *node2, int stack_n)
{
	t_push	*n1;
	t_push	*n2;

	n1 = stack_n == 2 ? node2 : node1;
	n2 = stack_n == 2 ? node1 : node2;
	ft_putstr("---------Stack A---------||---------Stack B---------\n");
	while (n1 != NULL || n2 != NULL)
	{
		if (n1 == NULL)
			ft_printf("|%24c||%24d|\n", ' ', n2->nbr);
		else if (n2 == NULL)
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