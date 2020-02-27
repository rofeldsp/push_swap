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

# define PUSH_A 1
# define PUSH_B 2
# define SWAP_A 4
# define SWAP_B 8
# define ROT_A	16
# define ROT_B	32
# define RROT_A 64
# define RROT_B 128
# define RR		256
# define RRR	512
# define SS		1024

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
** Structure for output
 */

typedef struct		s_output
{
	struct s_output	*next;
	struct s_output	*prev;
	int 			oper;
}					t_output;

/*
** Function declaration
 */

char		*parse_string(int argc, char **argv);
void		print_error(char *str);
int			main(int argc, char **argv);
t_push		*parse_stack(char *str);
void		add_list(t_push *node, char **str);
t_push 		*ft_swap(t_push *node);
void 		ft_push(t_push **node1, t_push **node2);
t_push 		*ft_rotate(t_push *node);
void 		free_node(t_push *node);
t_push		*ft_reverse(t_push *node);
void		ft_solve(t_push *node1);
int 		stack_length(t_push *node);
t_push		*allocate_struct(size_t size);
//t_push	 	*push_to_scnd_stack(t_push **node1);
t_push 		*push_to_scnd_stack(t_push **node1, t_output **out);
void		leave_marks(t_push *node1, int buf);
void		move_node_back(t_push **node1, t_push **node2, t_push **head,
						   t_output **out);
int 		buf_sequence(t_push *node1);
int 		check_sequence(t_push *node);
//void		sort_stacks(t_push **node1, t_push **node2);
void		sort_stacks(t_push **node1, t_push **node2, t_output **out);
int 		count_marked_nodes(t_push *node);
int 		find_smallest_nbr(t_push *node);
t_push		*go_to_start(t_push *node);
int 		len_to_start(t_push *node);
int 		len_to_end(t_push *node);
//t_push		*sort_first_stack(t_push *node, int nbr);
t_push		*sort_first_stack(t_push *node, int nbr, t_output **out);
//t_push		*rotate_ascending(t_push *node);
t_push		*rotate_ascending(t_push *node, t_output **out);
t_output	*allocate_output_struct(size_t size);
t_push		*ft_reverse_out(t_push *node, t_output **out, int stack_n);
void		ft_push_out(t_push **node1, t_push **node2,
													t_output **out, int s_n);
t_push		*ft_rotate_out(t_push *node, t_output **out, int stack_n);
t_push		*ft_swap_out(t_push *node, t_output **out, int stack_n);
t_output	*addlist_to_output(t_output **out);
t_output	*combine_rotations(t_output **out);
void		display_output(t_output *out);

#endif
