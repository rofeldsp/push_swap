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

# define ERR_MALLOC 	"Failed to allocate the memory\n"
# define STD_ERR		"Error"

/*
** Macroses
*/

# define DEBUG			2
# define COLOR			4
# define FILE			8
# define N_OPERS		16
# define EMPTY_NODE		4294967296
# define ALL_INDEXED	-4294967296
# define BUFFER			100
# define INTMAX 		2147483647
# define INTMIN			-2147483648

# define PUSH_A 		1
# define PUSH_B 		2
# define SWAP_A 		4
# define SWAP_B 		8
# define ROT_A			16
# define ROT_B			32
# define RROT_A 		64
# define RROT_B 		128
# define RR				256
# define RRR			512
# define SS				1024

/*
** Libraries
*/

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
** Structure for stack
*/

typedef struct			s_push
{
	struct s_push		*next;
	struct s_push		*prev;
	int					debug_opt;
	__int64_t			nbr;
	int					marker;
	int					index;
}						t_push;

/*
** Structure for output
*/

typedef struct			s_output
{
	struct s_output		*next;
	struct s_output		*prev;
	int					oper;
}						t_output;

/*
** Function declaration
*/

char					*parse_input(int argc, char **argv);
void					print_error(void);
t_push					*parse_stack(char *str);
void					add_list(t_push *node, char **str);
t_push					*ft_swap(t_push *node);
void					ft_push(t_push **node1, t_push **node2);
t_push					*ft_rotate(t_push *node);
void					free_node(t_push *node);
t_push					*ft_reverse(t_push *node);
void					ft_solve(t_push **node1, int *fd);
int						stack_length(t_push *node);
t_push					*allocate_struct(size_t size);
t_push					*push_to_scnd_stack(t_push **node1, t_output **out,
																int swapper);
int						leave_marks(t_push **node1, int buf);
void					move_node_back(t_push **node1, t_push **node2,
												t_push **head, t_output **out);
int						buf_sequence(t_push *node1);
int						check_sequence(t_push *node);
void					sort_stacks(t_push **node1, t_push **node2,
															t_output **out);
int						count_marked_nodes(t_push *node);
int						find_smallest_nbr(t_push *node);
int						find_largest_nbr(t_push *node);
t_push					*go_to_start(t_push *node);
int						len_to_start(t_push *node);
int						len_to_end(t_push *node);
t_push					*sort_first_stack(t_push *node, t_push *node2, int nbr,
																t_output **out);
t_push					*rotate_ascending(t_push *node, t_push *node2,
																t_output **out);
t_output				*allocate_output_struct(size_t size);
t_push					*ft_reverse_out(t_push *node, t_push *node2,
												t_output **out, int stack_n);
void					ft_push_out(t_push **node1, t_push **node2,
													t_output **out, int s_n);
t_push					*ft_rotate_out(t_push *node, t_push *node2,
												t_output **out, int stack_n);
t_push					*ft_swap_out(t_push *node, t_push *node2,
												t_output **out, int stack_n);
t_output				*addlist_to_output(t_output **out);
t_output				*combine_rotations(t_output **out);
void					display_output(t_output *out, int flag, int *fd);
t_push					*what_to_push(t_push *node, t_push *node2,
																t_output **out);
t_push					*rotate_to_push(t_push *node, t_push *node2,
												t_push *head, t_output **out);
t_output				*delete_node(t_output **out);
t_output				*put_rr(t_output **out);
t_output				*put_rrr(t_output **out);
int						len_to_push(t_push *node, int nbr);
int64_t					what_to_move(t_push *node1, t_push *node2);
void					free_output(t_output *node);
void					check_for_overload(char *str);
void					display_stacks(t_push *node1, t_push *node2,
																int stack_n);
int64_t					find_smallest_not_indexed(t_push *node);
int						best_sequence(t_push *node);
void					put_index(t_push **node);
void					mark_stack(t_push **node1, int i, int iters);
void					free_marks(t_push **node1);
int						check_index_sequence(t_push *node);
void					leave_marks_by_index(t_push **node1, int buf,
																int swapper);
int						leave_marks2(t_push **node1, int buf2, int	swapper);
void					leave_marks3(t_push **node1);
char					*ft_increase_buffer(char **str);
void					print_error_fd(void);
void					create_node2(t_push **node2);
int						ft_check_fd(t_push **node1);
void					fd_to_output(int flag, int *fd);

#endif
