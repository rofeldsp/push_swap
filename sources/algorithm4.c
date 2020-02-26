/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:15:34 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/26 13:15:35 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_output 	*delete_node(t_output **out)
{
//	t_output	*pre;
	t_output	*nex;
//
	nex = (*out)->next;
//	pre = (*out)->prev;
	(*out)->prev->next = (*out)->next;
	(*out)->next->prev = (*out)->prev;
	free(*out);
	return (nex);
}

/*
** Function that goes through all instructions of stacks ought to be printed
** and substitutes all the rotation_a and rotation_b with rotate_both and
** reverse_a and reverse_b with reverse_both if they are situated between
** pushes.
 */

t_output	*combine_rotations(t_output **out)
{
	t_output *head;
	int count_ra;
	int count_rra;
	int count_rb;
	int count_rrb;

	head = *out;
	while ((*out)->next != NULL)
	{
		count_ra = 0;
		count_rb = 0;
		count_rra = 0;
		count_rrb = 0;
		while (!((*out)->oper & (PUSH_A | PUSH_B)) && (*out)->next != NULL)
		{
			if ((*out)->oper & ROT_A)
				count_ra++;
			else if ((*out)->oper & ROT_B)
				count_rb++;
			else if ((*out)->oper & RROT_A)
				count_rra++;
			else if ((*out)->oper & RROT_B)
				count_rrb++;
			*out = (*out)->next;
		}
		while ((count_ra != 0 && count_rb != 0) ||
										(count_rra != 0 && count_rrb != 0))
		{
			if (count_ra != 0 && count_rb != 0)
			{
				if ((*out)->oper & ROT_A)
					*out = delete_node(out);
				else if ((*out)->oper & ROT_B)
				{
					count_ra--;
					count_rb--;
					(*out)->oper = RR;
				}
			}
			else if (count_rra != 0 && count_rrb != 0)
			{
				if ((*out)->oper & RROT_A)
					delete_node(out);
				else if ((*out)->oper & RROT_B)
				{
					count_rra--;
					count_rrb--;
					(*out)->oper = RRR;
				}
			}
			*out = (*out)->prev;
		}
		if ((*out)->next != NULL)
			*out = (*out)->next;
	}
	return (head); // обработать вариант, где head удаляется
}