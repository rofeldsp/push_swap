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

void		display_output2(t_output *out, int *fd)
{
	if (out->oper == ROT_A)
		write(*fd, "ra", 2);
	else if (out->oper == ROT_B)
		write(*fd, "rb", 2);
	else if (out->oper == RR)
		write(*fd, "rr", 2);
	else if (out->oper == RROT_A)
		write(*fd, "rra", 3);
	else if (out->oper == RROT_B)
		write(*fd, "rrb", 3);
	else if (out->oper == RRR)
		write(*fd, "rrr", 3);
}

void		display_output(t_output *out, int flag, int *fd)
{
	if (flag & FILE)
		*fd = open("output.txt", O_WRONLY);
	else
		*fd = 1;
	if (*fd == -1)
		print_error_fd();
	while (out != NULL)
	{
		if (out->oper == SWAP_A)
			write(*fd, "sa", 2);
		else if (out->oper == SWAP_B)
			write(*fd, "sb", 2);
		else if (out->oper == SS)
			write(*fd, "ss", 2);
		else if (out->oper == PUSH_A)
			write(*fd, "pa", 2);
		else if (out->oper == PUSH_B)
			write(*fd, "pb", 2);
		else
			display_output2(out, fd);
		write(*fd, "\n", 1);
		out = out->next;
	}
}

/*
** Function that goes through all instructions of stacks ought to be printed
** and substitutes all the rotation_a and rotation_b with rotate_both and
** reverse_a and reverse_b with reverse_both if they are situated between
** pushes.
**
** Counter variable consists of:
** 1) Counter of RA operations
** 2) Counter of RB operations
** 3) Counter of RRA operations
** 4) Counter of RRB operations
*/

void		combine_rotations3(t_output **out, int counter[4])
{
	while ((counter[0] != 0 && counter[1] != 0) ||
										(counter[2] != 0 && counter[3] != 0))
	{
		if (counter[0] != 0 && counter[1] != 0)
		{
			*out = put_rr(out);
			counter[0]--;
			counter[1]--;
		}
		else if (counter[2] != 0 && counter[3] != 0)
		{
			*out = put_rrr(out);
			counter[2]--;
			counter[3]--;
		}
		*out = (*out)->prev;
	}
}

void		combine_rotations2(t_output **out, int counter[4])
{
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	counter[3] = 0;
	while (!((*out)->oper & (PUSH_A | PUSH_B)) && (*out)->next != NULL)
	{
		if ((*out)->oper & ROT_A)
			counter[0]++;
		else if ((*out)->oper & ROT_B)
			counter[1]++;
		else if ((*out)->oper & RROT_A)
			counter[2]++;
		else if ((*out)->oper & RROT_B)
			counter[3]++;
		*out = (*out)->next;
	}
}

t_output	*combine_rotations(t_output **out)
{
	t_output	*head;
	int			counter[4];

	head = *out;
	while ((*out)->next != NULL)
	{
		combine_rotations2(out, counter);
		combine_rotations3(out, counter);
		if ((*out)->next != NULL)
			*out = (*out)->next;
	}
	return (head);
}
