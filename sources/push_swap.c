/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:24:07 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/19 13:24:10 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	char *str;

	if (argc == 1)
		print_error(ERR_ARG);
	else
		str = parse_string(argc, argv);
	parse_stack(str);
	free (str);
	return (0);
}
