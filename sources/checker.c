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
		print_error();
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
		if (!(ft_strncmp(str + i, "pa", 2)))
			ft_push(&node2, node1);
		else if (!(ft_strncmp(str + i, "pb", 2)))
			ft_push(node1, &node2);
		else if (!(ft_strncmp(str + i, "sa", 2)))
			*node1 = ft_swap(*node1);
		else if (!(ft_strncmp(str + i, "sb", 2)))
			node2 = ft_swap(node2);
		else if (!(ft_strncmp(str + i, "ss", 2)))
		{
			*node1 = ft_swap(*node1);
			node2 = ft_swap(node2);
		}
		else if (!(ft_strncmp(str + i, "rra", 3)))
			*node1 = ft_reverse(*node1);
		else if (!(ft_strncmp(str + i, "rrb", 3)))
			node2 = ft_reverse(node2);
		else if (!(ft_strncmp(str + i, "rrr", 3)))
		{
			*node1 = ft_reverse(*node1);
			node2 = ft_reverse(node2);
		}
		else if (!(ft_strncmp(str + i, "ra", 2)))
			*node1 = ft_rotate(*node1);
		else if (!(ft_strncmp(str + i, "rb", 2)))
			node2 = ft_rotate(node2);
		else if (!(ft_strncmp(str + i, "rr", 2)))
		{
			*node1 = ft_rotate(*node1);
			node2 = ft_rotate(node2);
		}
		else
			print_error();
		if (!(ft_strncmp(str + i, "rrr", 3)) || !(ft_strncmp(str + i, "rra", 3))
				|| !(ft_strncmp(str + i, "rrb", 3)))
			i += 4;
		else
			i += 3;
	}
}

int 	check_output(t_push **node1)
{
	int ret;
	int buf;
	char *str;

	buf = 0;
	if (!(str = ft_strnew(BUFFER + 1)))
		print_error();
	while (1)
	{
		if ((ret = (read(0, str + buf, BUFFER))) == 0)
			break ;
		str = increase_buffer(&str);
		buf += ret;
	}
	parse_instructions(str, node1);
	if (*node1 == NULL)
		print_error();
	if (check_sequence(*node1) == stack_length(*node1) - 1)
		return (1);
	return (0);
}

int 	main(int argc, char **argv)
{
	int result;
	char *str;
	t_push *node;

	if (argc == 1)
	{
		print_error();
		exit(33); // почему без этого не компилится?
	}
	else
		str = parse_string(argc, argv);
	node = parse_stack(str);
	result = check_output(&node);
	if (result == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_node(node);
	return (0);
}
