/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:52:26 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/19 13:52:27 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_spaces(char *str)
{
	int		i;
	int		j;
	int		spaces;

	j = ft_strlen(str);
	i = 0;
	spaces = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			spaces++;
		i++;
	}
	return (spaces == j ? 1 : 0);
}

char		*parse_input(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	if (*argv[i] == '\0')
		print_error();
	if (check_spaces(argv[i]) == 1)
		print_error();
	if (!(str = ft_strdup(argv[i++])))
		print_error();
	while (i < argc)
	{
		if (check_spaces(argv[i]) == 1)
			print_error();
		if (!(tmp = ft_strjoin(str, " ")))
			print_error();
		free(str);
		if (*argv[i] == '\0')
			print_error();
		if (!(str = ft_strjoin(tmp, argv[i++])))
			print_error();
		free(tmp);
	}
	return (str);
}
