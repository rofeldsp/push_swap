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
		i++;
	return(i);
}

void		add_list(t_push *node, char **str)
{
	int 	j;
	t_push	*node2;

	if (!(node2 = malloc(sizeof(t_push))))
		print_error(ERR_MALLOC);
	node2->debug_opt = node->debug_opt;
	node2->next = NULL;
	node->next = node2;
	node2->prev = node;
	j = 0;
	while (ft_isdigit(str[0][j]))
		j++;
	if (j == ft_strlen(str[0]))
		node2->nbr = ft_atoi(str[0]);
	if (*(str + 1))
		add_list(node2, str + 1);
}

t_push		*parse_stack(char *str)
{
	int 	i;
	int		j;
	t_push	*node;
	char	**str2;

	i = 0;
	j = 0;
	if (!(node = malloc(sizeof(t_push))))
		print_error(ERR_MALLOC);
	str2 = ft_strsplit(str, ' ');
	if (ft_strequ(str2[0], "-v"))
	{
		node->debug_opt |= DEBUG;
		i++;
	}
	while (ft_isdigit(str2[i][j]))
		j++;
	if (j == ft_strlen(str2[i]))
		node->nbr = ft_atoi(str2[i++]);
	else
		print_error(STD_ERR);
	node->next = NULL;
	node->prev = NULL;
	if (*str2 + 1)
		add_list(node, str2 + 1);
	i = 0;
	while (str2[i])
		free(str2[i++]);
	free(str2);
	return(node);
}
