/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:39:27 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/28 16:39:29 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char 	*increase_buffer(char **str)
{
	char *dest;

	if (!(dest = ft_strnew(ft_strlen(*str) + BUFFER + 1)))
		print_error(ERR_MALLOC);
	dest = ft_strcpy(dest, *str);
	free(*str);
	return(dest);
}

void	parse_instructions(char *str, t_push **node1)
{
	int i;
	t_push	*node2;

	i = 0;
	node2 = allocate_struct(sizeof(t_push));
	node2->nbr = EMPTY_NODE;
	while(str[i])
	{
		if (ft_strncmp(str, "pa", 2))
			ft_push(&node2, node1);
		else if (ft_strncmp(str, "pb", 2))
			ft_push(node1, &node2);
		else if (ft_strncmp(str, "sa", 2))
			*node1 = ft_swap(*node1);
		else if (ft_strncmp(str, "sb", 2))
			node2 = ft_swap(node2);
		else if (ft_strncmp(str, "ss", 2))
		{
			*node1 = ft_swap(*node1);
			node2 = ft_swap(node2);
		}
		else if (ft_strncmp(str, "rra", 3))
			*node1 = ft_reverse(*node1);
		else if (ft_strncmp(str, "rrb", 3))
			node2 = ft_reverse(node2);
		else if (ft_strncmp(str, "rrr", 3))
		{
			*node1 = ft_reverse(*node1);
			node2 = ft_reverse(node2);
		}
		else if (ft_strncmp(str, "ra", 2))
			*node1 = ft_rotate(*node1);
		else if (ft_strncmp(str, "rb", 2))
			node2 = ft_rotate(node2);
		else if (ft_strncmp(str, "rr", 2))
		{
			*node1 = ft_rotate(*node1);
			node2 = ft_rotate(node2);
		}
	}
}

int 	check_output(t_push **node1)
{
	int ret;
	char *str;

	if (!(str = ft_strnew(BUFFER + 1)))
		print_error(ERR_MALLOC);
	while (1)
	{
		if ((ret = read(1, str, BUFFER)) == 0)
			break ;
		str = increase_buffer(&str);
	}
//	parse_instructions(&out, str);
	return (1);
}

int 	main(int argc, char **argv)
{
	int result;
	char *str;
	t_push *node;

	if (argc == 1)
	{
		print_error(ERR_ARG);
		exit(33); // почему без этого не компилится?
	}
	else
		str = parse_string(argc, argv);
	node = parse_stack(str);
	result = check_output(&node);
}
