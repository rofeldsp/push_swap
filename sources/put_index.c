//
// Created by Igor Krasnov on 08.03.20.
//

#include "push_swap.h"

void	leave_marks3(t_push **node1)
{
	t_push		*head;
	int			num;

	head = *node1;
	num = (*node1)->nbr;
	(*node1) = (*node1)->next;
	while (*node1 != NULL)
	{
		if ((*node1)->nbr > num)
			num = (*node1)->nbr;
		else
			(*node1)->marker = 1;
		*node1 = (*node1)->next;
	}
	*node1 = head;
}

int 	leave_marks2(t_push **node1, int buf2, int swapper)
{
	if (best_sequence(*node1) > check_sequence(*node1))
	{
		if (best_sequence(*node1) == check_index_sequence(*node1))
		{
			leave_marks_by_index(node1, buf2, swapper);
			return (0);
		}
		else
		{
			(*node1)->marker = 2;
			*node1 = ft_swap(*node1);
			swapper = 1;
			if (check_index_sequence(*node1) > check_sequence(*node1))
			{
				leave_marks_by_index(node1, buf2, swapper);
				return (swapper);
			}
			return (-2);
		}
	}
	return (-1);
}

int			count_marked_nodes(t_push *node)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		if (node->marker == 1)
			i++;
		node = node->next;
	}
	return (i);
}

int64_t		find_smallest_not_indexed(t_push *node)
{
	int i;

	while (node->index != 0)
	{
		if (node->next == NULL)
			return (ALL_INDEXED);
		node = node->next;
	}
	i = node->nbr;
	while (node != NULL)
	{
		if (node->nbr < i && node->index == 0)
			i = node->nbr;
		node = node->next;
	}
	return (i);
}

void	put_index(t_push **node)
{
	int64_t 	smallest_n;
	int			i;
	int			j;

	i = 1;
	j = 0;
	while ((smallest_n = find_smallest_not_indexed(*node)) != ALL_INDEXED)
	{
		while ((*node)->nbr != smallest_n)
		{
			*node = ft_rotate(*node);
			j++;
		}
		(*node)->index = i++;
	}
	while (j-- != 0)
		*node = ft_reverse(*node);
}

