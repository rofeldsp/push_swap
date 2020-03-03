# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 12:55:08 by rofeldsp          #+#    #+#              #
#    Updated: 2020/02/19 12:55:10 by rofeldsp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = push_swap

NAME2 = checker

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

LIBA = libft/libft.a

DIR_S = sources/

DIR_O = object_files

HEADER = include

SOURCE_FILES = push_swap.c \
            parse_string.c \
            print_error.c \
            parse_stack.c \
            algorithm.c \
            algorithm2.c \
            algorithm3.c \
            algorithm4.c \
            algorithm5.c \
            algorithm6.c \
            free_node.c \
            allocate_struct.c \
            instructions.c \
            instructions_output.c

SOURCE_FILES_CHECKER = checker.c \
            parse_string.c \
            print_error.c \
            parse_stack.c \
            free_node.c \
            algorithm.c \
            algorithm2.c \
            algorithm3.c \
            algorithm4.c \
            algorithm5.c \
            algorithm6.c \
            allocate_struct.c \
            instructions.c \
            instructions_output.c

SOURCES = $(addprefix $(DIR_S), $(SOURCE_FILES))

SOURCES_CHECKER = $(addprefix $(DIR_S), $(SOURCE_FILES_CHECKER))

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME) $(NAME2)

$(NAME):
	@make -C $(LIBFT)
	@ranlib $(LIBA)
	@$(CC) $(FLAGS) $(SOURCES) -I $(HEADER) $(LIBA) -o $(NAME)

$(NAME2):
	@$(CC) $(FLAGS) $(SOURCES_CHECKER) -I $(HEADER) $(LIBA) -o $(NAME2)

clean:
# 	@rm -f $(OBJS)
# 	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
