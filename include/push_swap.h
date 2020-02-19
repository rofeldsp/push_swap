/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:22:31 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/19 13:22:32 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** Error macroses
 */

# define ERR_ARG "No arguments found"

/*
** Libraries
 */

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

/*
** Structure for stack
 */

typedef struct	s_push
{
	s_push		*next;
	int			debug_opt;
	int			nbr;
}				*node;

/*
** Function declaration
 */

char		*parse_string(int argc, char **argv);
void		print_error(char *str);
int			main(int argc, char **argv);

#endif
