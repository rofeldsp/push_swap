#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 12:55:08 by rofeldsp          #+#    #+#              #
#    Updated: 2020/02/19 12:55:10 by rofeldsp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

PUSH_SWAP = push_swap

CHECKER = checker

FLAGS = -Wall -Wextra -Werror

DIR_LIBFT = ./libft

DIR_SOURCES = sources/

DIR_HEADER = include

HEADER = include/push_swap.h

SOURCES_FILES_PUSH_SWAP = push_swap.c \
			parse_string.c \
			print_error.c \
			parse_stack.c \
			ft_check_fd.c \
			ft_solve.c \
			sort_stacks.c \
			sort_first_stack.c \
			display_output.c \
			what_to_push.c \
			put_reverses.c \
			push_to_scnd_stack.c \
			free_node.c \
			put_index.c \
			display_stacks.c \
			allocate_struct.c \
			instructions.c \
			instructions_output.c \
			find_best_sequence.c

SOURCE_FILES_CHECKER = checker.c \
			increase_buffer.c \
			parse_string.c \
			print_error.c \
			create_node2.c\
			parse_stack.c \
			put_index.c \
			ft_check_fd.c \
			free_node.c \
			display_stacks.c \
			ft_solve.c \
			put_reverses.c \
			sort_stacks.c \
			sort_first_stack.c \
			display_output.c \
			what_to_push.c \
			push_to_scnd_stack.c \
			allocate_struct.c \
			instructions.c \
			find_best_sequence.c \
			instructions_output.c

SOURCES_PUSH_SWAP = $(addprefix $(DIR_SOURCES), $(SOURCES_FILES_PUSH_SWAP))
SOURCES_CHECKER = $(addprefix $(DIR_SOURCES), $(SOURCE_FILES_CHECKER))

OBJECTS_PUSH_SWAP = $(SOURCES_PUSH_SWAP:.c=.o)
OBJECTS_CHECKER = $(SOURCES_CHECKER:.c=.o)

.PHONY: all clean fclean re force

all: lib $(CHECKER) $(PUSH_SWAP)

lib:
	make -C ./libft

$(CHECKER): $(OBJECTS_CHECKER)
	$(CC) $(FLAGS) $(OBJECTS_CHECKER) -L $(DIR_LIBFT) -lft -o $(CHECKER)

$(PUSH_SWAP): $(OBJECTS_PUSH_SWAP)
	$(CC) $(FLAGS) $(OBJECTS_PUSH_SWAP) -L $(DIR_LIBFT) -lft -o $(PUSH_SWAP)

$(DIR_SOURCES)%.o: $(DIR_SOURCES)%.c $(HEADER)
	$(CC) $(FLAGS) -I $(DIR_HEADER) -c $< -o $@

clean:
	make clean -C $(DIR_LIBFT)
	rm -f $(OBJECTS_PUSH_SWAP) $(OBJECTS_CHECKER)

fclean: clean
	rm -f $(CHECKER)
	rm -f $(PUSH_SWAP)
	make fclean -C $(DIR_LIBFT)

re: fclean all
