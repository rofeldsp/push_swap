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

# define ERR_ARG 	"No arguments found\n"
# define ERR_MALLOC "Failed to allocate the memory\n"
# define STD_ERR	"Error: input should consist from digits only"

/*
** Macroses
 */

# define DEBUG	2
# define EMPTY_NODE 4294967296

/*
** Libraries
 */

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

/*
** Structure for stack
 */

typedef struct		s_push
{
	struct s_push	*next;
	struct s_push	*prev;
	int				debug_opt;
	__int64_t		nbr;
	int 			marker;
}					t_push;

/*
** Function declaration
 */

char		*parse_string(int argc, char **argv);
void		print_error(char *str);
int			main(int argc, char **argv);
t_push		*parse_stack(char *str);
void		add_list(t_push *node, char **str);
t_push 		*ft_swap(t_push *node);
void 		ft_push(t_push *node1, t_push *node2);
void 		ft_push(t_push *node1, t_push *node2);
t_push 		*ft_rotate(t_push *node);
void 		free_node(t_push *node);
t_push		*ft_reverse(t_push *node);
void		ft_solve(t_push *node1);
int 		stack_length(t_push *node);

#endif
