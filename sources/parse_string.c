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

char		*parse_input(int argc, char **argv)
{
	int		i;
	char	*str;
	char 	*tmp;

	i = 1;
	if (!(str = ft_strdup(argv[i++])))
		print_error();
	while (i < argc)
	{
		if (!(tmp = ft_strjoin(str, " ")))
			print_error();
		free (str);
		if (!(str = ft_strjoin(tmp, argv[i++])))
			print_error();
		free (tmp);
	}
	return (str);
}
