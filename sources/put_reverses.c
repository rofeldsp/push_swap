//
// Created by Igor Krasnov on 09.03.20.
//

#include "push_swap.h"

t_output *put_rr(t_output **out)
{
	t_output	*head;
	int			switcher;

	head = *out;
	switcher = 1;
	while (!((*out)->oper & ROT_A) && !((*out)->oper & ROT_B))
		*out = (*out)->prev;
	if ((*out)->oper & ROT_A)
		*out = delete_node(out);
	else if ((*out)->oper & ROT_B)
	{
		switcher = 2;
		(*out)->oper = RR;
	}
	while (!((*out)->oper & (switcher == 1 ? ROT_B : ROT_A)))
		*out = (*out)->prev;
	if (switcher == 1)
		(*out)->oper = RR;
	else
		*out = delete_node(out);
	return (head);
}

t_output *put_rrr(t_output **out)
{
	t_output	*head;
	int			switcher;

	head = *out;
	switcher = 1;
	while (!((*out)->oper & RROT_A) && !((*out)->oper & RROT_B))
		*out = (*out)->prev;
	if ((*out)->oper & RROT_A)
		*out = delete_node(out);
	else if ((*out)->oper & RROT_B)
	{
		switcher = 2;
		(*out)->oper = RRR;
	}
	while (!((*out)->oper & (switcher == 1 ? RROT_B : RROT_A)))
		*out = (*out)->prev;
	if (switcher == 1)
		(*out)->oper = RRR;
	else
		*out = delete_node(out);
	return (head);
}
