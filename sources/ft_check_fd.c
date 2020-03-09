/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:27:40 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/03/09 14:27:42 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_fd(t_push **node1)
{
	int		fd;

	if ((*node1)->debug_opt & FILE)
		fd = open("output.txt", O_RDONLY);
	else
		fd = 0;
	if (fd == -1)
		print_error_fd();
	return (fd);
}

void	fd_to_output(int flag, int *fd)
{
	if (flag & FILE)
		*fd = open("output.txt", O_WRONLY);
	else
		*fd = 1;
	if (*fd == -1)
		print_error_fd();
}
