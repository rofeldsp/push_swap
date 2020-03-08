//
// Created by Igor Krasnov on 08.03.20.
//

#include "push_swap.h"

int 	leave_marks2(t_push **node1, int buf2, int	swapper)
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
		}
	}
	return (-1);
}