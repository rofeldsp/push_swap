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

NAME = libft.a

DIR_HEADER = include/

HEADER = include/libft.h \
        include/ft_printf.h

SRCS = ft_atoi.c \
    ft_atoll.c \
    ft_bzero.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_itoa.c \
    ft_lstadd.c \
    ft_lstdel.c \
    ft_lstdelone.c \
    ft_lstiter.c \
    ft_lstmap.c \
    ft_lstnew.c \
    ft_memalloc.c \
    ft_memccpy.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memdel.c \
    ft_memmove.c \
    ft_memset.c \
    ft_putchar.c \
    ft_putchar_fd.c \
    ft_putendl.c \
    ft_putendl_fd.c \
    ft_putnbr.c \
    ft_putnbr_fd.c \
    ft_putstr.c \
    ft_putstr_fd.c \
    ft_strcat.c \
    ft_strchr.c \
    ft_strclr.c \
    ft_strcmp.c \
    ft_strcpy.c \
    ft_strdel.c \
    ft_strdup.c \
    ft_strequ.c \
    ft_striter.c \
    ft_striteri.c \
    ft_strjoin.c \
    ft_strlcat.c \
    ft_strlen.c \
    ft_strmap.c \
    ft_strmapi.c \
    ft_strncat.c \
    ft_strncmp.c \
    ft_strncpy.c \
    ft_strnequ.c \
    ft_strnew.c \
    ft_strnstr.c \
    ft_strrchr.c \
    ft_strsplit.c \
    ft_strstr.c \
    ft_strsub.c \
    ft_strtrim.c \
    ft_tolower.c \
    ft_toupper.c \
    ft_printf.c \
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

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c $(HEADER)
	@gcc -Wall -Wextra -Werror -I $(DIR_HEADER) -c $< -o $@

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
