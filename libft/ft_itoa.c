/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:18:41 by rofeldsp          #+#    #+#             */
/*   Updated: 2019/09/17 12:59:25 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*cut1(int64_t j, int64_t n, int64_t c)
{
	char				*dst;
	int64_t				b;

	b = n;
	while (b / 10 > 0)
	{
		j++;
		b = b / 10;
	}
	dst = (char*)malloc(sizeof(char) * (j + 1));
	if (dst == NULL)
		return (NULL);
	dst[j] = '\0';
	j--;
	while (n / 10 > 0)
	{
		dst[j] = '0' + n % 10;
		n = n / 10;
		j--;
	}
	dst[j] = '0' + n % 10;
	if (c < 0)
		dst[j - 1] = '-';
	return (dst);
}

char			*ft_itoa(int64_t n)
{
	__int64_t		j;
	char			*dst;
	__int64_t		c;

	j = 1;
	c = n;
	if (n < 0)
	{
		if (n - 1 > n)
			return (ft_strdup("-9223372036854775808"));
		n = -n;
		j++;
	}
	dst = cut1(j, n, c);
	return (dst);
}
