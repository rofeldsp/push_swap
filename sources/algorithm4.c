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
	t_output	*nex;

	nex = (*out)->next;
	(*out)->prev->next = (*out)->next;
	(*out)->next->prev = (*out)->prev;
	free(*out);
	return (nex);
}

void 		display_output2(t_output *out)
{
	if (out->oper == ROT_A)
		write(1, "ra", 2);
	else if (out->oper == ROT_B)
		write(1, "rb", 2);
	else if (out->oper == RR)
		write(1, "rr", 2);
	else if (out->oper == RROT_A)
		write(1, "rra", 3);
	else if (out->oper == RROT_B)
		write(1, "rrb", 3);
	else if (out->oper == RRR)
		write(1, "rrr", 3);
}

void		display_output(t_output *out)
{
	while (out != NULL)
	{
		if (out->oper == SWAP_A)
			write(1, "sa", 2);
		else if (out->oper == SWAP_B)
			write(1, "sb", 2);
		else if (out->oper == SS)
			write(1, "ss", 2);
		else if (out->oper == PUSH_A)
			write(1, "pa", 2);
		else if (out->oper == PUSH_B)
			write(1, "pb", 2);
		display_output2(out);
		if (out->next != NULL)
			write(1, "\n", 1);
		out = out->next;
	}
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
				*out = put_rr(out);
				count_ra--;
				count_rb--;
			}
			else if (count_rra != 0 && count_rrb != 0)
			{
				*out = put_rrr(out);
				count_rra--;
				count_rrb--;
			}
			*out = (*out)->prev;
		}
		if ((*out)->next != NULL)
			*out = (*out)->next;
	}
	return (head);
}