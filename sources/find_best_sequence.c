/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_sequence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:13:02 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/03/09 12:13:04 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sequence(t_push *node)
{
	int		i;
	int		num;

	i = 1;
	num = node->nbr;
	while (node->next != NULL)
	{
		if (node->nbr > num)
		{
			num = node->nbr;
			i++;
		}
		node = node->next;
	}
	if (node->nbr > num)
		i++;
	return (i);
}

int		check_index_sequence(t_push *node)
{
	int		i;
	int		num;

	i = 1;
	num = node->index;
	while (node->next != NULL)
	{
		if (node->index == num + i)
			i++;
		node = node->next;
	}
	if (node->index == num + i)
		i++;
	return (i);
}

int		best_sequence(t_push *node)
{
	int len;
	int swap_len;
	int index_len;
	int index_swap;

	len = check_sequence(node);
	node = ft_swap(node);
	swap_len = check_sequence(node);
	index_swap = check_index_sequence(node);
	node = ft_swap(node);
	index_len = check_index_sequence(node);
	index_len = index_swap > index_len ? index_swap : index_len;
	len = index_len > len ? index_len : len;
	return (swap_len > len ? swap_len : len);
}
