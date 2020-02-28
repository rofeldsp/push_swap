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
	while(str[i])
	{
		if (ft_strncmp(str, "pa", 2))
			ft_push(&node2, node1);
		else if (ft_strncmp(str, "pb", 2))
			ft_push(node1, &node2);
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
	parse_instructions(&out, str);
}

int 	main(int argc, char **argv)
{
	int result;

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
