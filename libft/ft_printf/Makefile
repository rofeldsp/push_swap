# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 14:10:42 by rofeldsp          #+#    #+#              #
#    Updated: 2019/09/20 12:09:12 by rofeldsp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = ../../libft

DIR_S = sources

DIR_O = object_files

HEADER = include

SOURCES = ft_printf.c \
          get_flag.c \
          get_precision.c \
          get_size.c \
          get_type.c \
          get_width.c \
          parse_char.c \
          parse_string.c \
          parse_decimal.c \
          parse_percent.c \
          parse_hexodecimal.c \
          ft_putstr_printf.c \
          parse_octal.c \
          parse_udecimal.c \
          parse_pointer.c \
          parse_float.c \
          parse_float_2.c \
          print_color.c \
          parse_binary.c \
          parse_unicode.c \
          additional_functions.c \
          adjust_to_width.c \
          adjust_to_flag.c \
          adjust_to_precision.c \
          adjust_to_precision_2.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
# 	@make -C $(LIBFT)
# 	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p object_files
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
# 	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
# 	@make fclean -C $(LIBFT)

re: fclean all
