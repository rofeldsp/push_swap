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

char		*parse_string(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;
	char 	*tmp;

	i = 1;
	j = 0; // добавить про флаг -v
	if (!(str = ft_strdup(argv[i++])))
		print_error(ERR_MALLOC);
	while (i < argc)
	{
		if (!(tmp = ft_strjoin(str, " ")))
			print_error(ERR_MALLOC);
		free (str); // добавить обработку ошибок
		if (!(str = ft_strjoin(tmp, argv[i++])))
			print_error(ERR_MALLOC);
		free (tmp);
	}
//	ft_putstr(str);
	return (str);
}
