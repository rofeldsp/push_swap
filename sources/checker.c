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

int		parse_instructions3(char *str, int i)
{
	if (!(ft_strncmp(str + i, "rrr", 3)) || !(ft_strncmp(str + i, "rra", 3))
		|| !(ft_strncmp(str + i, "rrb", 3)))
		i += 4;
	else
		i += 3;
	return (i);
}

void	parse_instructions2(t_push **node1, t_push **node2, int i, char *str)
{
	if (!(ft_strncmp(str + i, "pa", 2)))
		ft_push(node2, node1);
	else if (!(ft_strncmp(str + i, "pb", 2)))
		ft_push(node1, node2);
	else if (!(ft_strncmp(str + i, "sa", 2)))
		*node1 = ft_swap(*node1);
	else if (!(ft_strncmp(str + i, "sb", 2)))
		*node2 = ft_swap(*node2);
	else if (!(ft_strncmp(str + i, "ss", 2)))
	{
		*node1 = ft_swap(*node1);
		*node2 = ft_swap(*node2);
	}
	else if (!(ft_strncmp(str + i, "ra", 2)))
		*node1 = ft_rotate(*node1);
	else if (!(ft_strncmp(str + i, "rb", 2)))
		*node2 = ft_rotate(*node2);
	else if (!(ft_strncmp(str + i, "rr", 2)))
	{
		*node1 = ft_rotate(*node1);
		*node2 = ft_rotate(*node2);
	}
	else
		print_error();
}

void	parse_instructions(char *str, t_push **node1)
{
	int		i;
	t_push	*node2;

	i = 0;
	node2 = allocate_struct(sizeof(t_push));
	node2->nbr = EMPTY_NODE;
	while (str[i])
	{
		create_node2(&node2);
		if (!(ft_strncmp(str + i, "rra", 3)))
			*node1 = ft_reverse(*node1);
		else if (!(ft_strncmp(str + i, "rrb", 3)))
			node2 = ft_reverse(node2);
		else if (!(ft_strncmp(str + i, "rrr", 3)))
		{
			*node1 = ft_reverse(*node1);
			node2 = ft_reverse(node2);
		}
		else
			parse_instructions2(node1, &node2, i, str);
		i = parse_instructions3(str, i);
	}
	free_node(node2);
}

int		check_output(t_push **node1, int *fd)
{
	int		ret;
	int		buf;
	char	*str;
	int		stack_len;

	*fd = ft_check_fd(node1);
	stack_len = stack_length(*node1);
	buf = 0;
	if (!(str = ft_strnew(BUFFER + 1)))
		print_error();
	while (1)
	{
		if ((ret = (read(*fd, str + buf, BUFFER))) == 0)
			break ;
		str = ft_increase_buffer(&str);
		buf += ret;
	}
	parse_instructions(str, node1);
	if (*node1 == NULL)
		print_error();
	free(str);
	if (check_sequence(*node1) == stack_length(*node1) && stack_length(*node1)
																== stack_len)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		result;
	char	*str;
	t_push	*node;
	int		fd;

	fd = 0;
	if (argc == 1)
		return (0);
	str = parse_input(argc, argv);
	if (!(node = parse_stack(str)))
	{
		free(str);
		return (0);
	}
	result = check_output(&node, &fd);
	if (fd >= 3)
		close(fd);
	if (result == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_node(node);
	free(str);
	return (0);
}
