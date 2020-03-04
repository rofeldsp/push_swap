/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:56:59 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/19 14:57:02 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 		stack_length(t_push *node)
{
	int i;

	if (node == NULL)
		return (0);
	else
		i = 1;
	while (node->next != NULL)
	{
		node = node->next;
		i++;
	}
	return(i);
}

void		check_for_errors(t_push **node)
{
	t_push *head;
	t_push *head2;

	head2 = *node;
	while (*node != NULL)
	{
		if (((*node)->nbr) > INTMAX || (*node)->nbr < INTMIN)
			print_error();
		head = head2;
		while (head != NULL)
		{
			if ((head->nbr == (*node)->nbr) && head != *node)
				print_error();
			head = head->next;
		}
		*node = (*node)->next;
	}
	*node = head2;
}

void		add_list(t_push *node, char **str)
{
//	int 	j;
	t_push	*node2;

	if (!(node2 = malloc(sizeof(t_push))))
		print_error();
	node2->debug_opt = node->debug_opt;
	node2->next = NULL;
	node2->marker = -1;
	node->next = node2;
	node2->prev = node;
//	j = 0;
//	if (str[0][0] == '-' && str[0][1])
//		j++;
//	while (ft_isdigit(str[0][j]))
//		j++;
	check_for_overload(*str);
//	if (j == (int)ft_strlen(str[0]))
		node2->nbr = ft_atoll(str[0]);
//	else
//		print_error();
	if (*(str + 1))
		add_list(node2, str + 1);
}

void 		check_for_overload(char *str)
{
	int j;
//	int64_t nbr;

	j = 0;
	if (str[j] == '-' && str[j + 1])
		j++;
	while (ft_isdigit(str[j]))
		j++;
	if (j != (int)ft_strlen(str))
		print_error();
	if (str[0] == '-')
	{
		if (ft_atoll(str) > 0)
			print_error();
	}
	else
		if (ft_atoll(str) < 0)
			print_error();
}

t_push		*parse_stack(char *str)
{
	int 	i;
//	int		j;
	t_push	*node;
	char	**str2;

	i = 0;
//	j = 0;
	if (!(node = malloc(sizeof(t_push))))
		print_error();
	str2 = ft_strsplit(str, ' ');
	if (ft_strequ(str2[i], "-v"))
	{
		node->debug_opt |= DEBUG;
		i++;
	}
	if (ft_strequ(str2[i], "-c"))
	{
		node->debug_opt |= COLOR;
		i++;
	}
//	if (str2[i][j] == '-' && str2[i][j + 1])
//		j++;
//	while (ft_isdigit(str2[i][j]))
//		j++;
	check_for_overload(str2[i]);
//	if (j == (int)ft_strlen(str2[i]))
		node->nbr = ft_atoll(str2[i++]);
//	else
//		print_error();
	node->next = NULL;
	node->prev = NULL;
	node->marker = -1;
	if (*(str2 + 1))
		add_list(node, str2 + 1);
	i = 0;
	while (str2[i])
		free(str2[i++]);
	free(str2);
	check_for_errors(&node);
	return(node);
}
