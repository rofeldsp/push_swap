/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:16:45 by rofeldsp          #+#    #+#             */
/*   Updated: 2019/09/11 22:25:50 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char			*t;
	unsigned int	i;

	i = 0;
	t = (char*)s;
	while (i < n)
	{
		t[i] = '\0';
		i++;
	}
}