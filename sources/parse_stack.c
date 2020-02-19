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

__int64_t 	parse_nbr(char **str)
{
	int			i;
	__int64_t 	result;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] == 'v')
			return (result |= DEBUG);
		else if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= 0 && str[i] <= '9')

		}
	}
}

t_list		*parse_stack(char *str)
{
	int 	i;
	int		j;
	t_list	*node;
	t_list 	*tmp;
	char	**str2;

	i = 0;
	*node = malloc(sizeof(t_list));
	str2 = ft_strsplit(str, ' ');
	if (ft_strequ(str2[0], "-v"))
	{
		node->debug_opt |= DEBUG;
		i++;
	}
	while (str2[i])
	{
		j = 0;
		if (i != 0)
		while (ft_isdigit(str[i][j]))
			j++;
		if (j = ft_strlen(str[i]))
			node->nbr = ft_itoa(str[i]);
	}
	// нужен цикл, возможно вложенная функция, чтобы выделялась память под структуру,
	// а потом уже возвращался указатель на первый элемент. Либо вложенную функцию
	// надо написать, либо придумать, как использовать библиотечную функцию
//	node->nbr = parse_nbr(&str); // добавить обработку DEBUG
	node->next = NULL;
	tmp = node;
}
