/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions_checker.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:48:25 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/03/09 11:48:27 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_increase_buffer(char **str)
{
	char *dest;

	if (!(dest = ft_strnew(ft_strlen(*str) + BUFFER + 1)))
		print_error();
	dest = ft_strcpy(dest, *str);
	free(*str);
	return (dest);
}
