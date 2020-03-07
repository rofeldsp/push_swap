/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:58:26 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 11:58:31 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Standard libraries
*/

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

/*
** Own library
*/

# include "../../libft.h"

/*
** Node definition and macroses
*/

# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[34m"
# define PURPLE		"\e[35m"
# define CYAN		"\e[36m"
# define EOC		"\e[0m"

# define BUFF_SIZE	100
# define MINUS		1
# define PLUS		2
# define SPACE		4
# define ZERO		8
# define OCTO		16

# define H			1
# define HH			2
# define L			4
# define LL			8
# define FLOAT_L	16
# define UNIC		32

# define USHRT_MAX	65535
# define CHAR_BIT	8
# define SCHAR_MIN	-128
# define SCHAR_MAX	127
# define UCHAR_MAX	255
# define CHAR_MIN	-128
# define CHAR_MAX	127
# define SHRT_MIN	-32768
# define SHRT_MAX	32767
# define INT_MIN	−2147483648
# define INT_MAX	2147483647
# define UINT_MAX	4294967295
# define LONG_MIN	−9223372036854775808
# define LONG_MAX	9223372036854775807
# define ULONG_MAX	18446744073709551615
# define LLONG_MIN	-9223372036854775808
# define LLONG_MAX	9223372036854775807
# define ULLONG_MAX	18446744073709551615

typedef struct		s_print
{
	va_list			ap;
	char			*input;
	char			*buffer;
	int				pointer;
	unsigned int	flag;
	unsigned int	size;
	__int64_t		number;
	__uint64_t		unumber;
	long double		fnumber;
	int				empty_space;
	int				width;
	int				precision;
	int				end_of_field;
	int				field_start;
	int				count_nulls;
	int				buffer_size;
	int				return_status;
	int				pointer_buf;
}					t_print;

/*
**	Functions. Each function with index (e.g. parse_pointer2 - is a shortcut
** 	to function without index, so they both will be less then 25 lines, as
** 	specified by 42 code norm rules. If _v2 is used, it means that another
** version of same function is declared
*/

int					ft_printf(const char *str, ...);
int					ft_dprintf(int fd, const char *str, ...);
t_print				print_arg(t_print node);
t_print				get_type(t_print node);
char				*increase_buffer(char **str, t_print *node);
t_print				parse_char(t_print node);
t_print				parse_string(t_print node);
t_print				get_flag(t_print node);
t_print				get_width(t_print node);
t_print				get_precision(t_print node);
t_print				get_size(t_print node);
t_print				adjust_to_width(t_print node, int len);
t_print				adjust_to_width2(t_print node, int len);
t_print				adjust_to_precision(t_print node, int len, char **str);
t_print				adjust_to_precision_v3(t_print node, int len, char **str);
t_print				adjust_to_flag(t_print node, int len);
t_print				parse_decimal(t_print node);
t_print				parse_udecimal(t_print node);
t_print				adjust_to_flag_v2(t_print node, int len, char c, char *str);
t_print				adjust_to_flag_v3(t_print node, int len, char *str);
void				free_flags(t_print *node);
t_print				parse_percent(t_print node);
t_print				parse_hexodecimal(t_print node, char c);
char				*ft_itoa_base(__uint64_t nb, int base, char c);
char				*ft_itoa_base2(int i, char **str);
void				check_overflow(t_print *node);
void				adjust_to_precision_v2(t_print *node, char **str);
int					ft_putstr_printf(char *str, int a);
int					ft_putstr_dprintf(int fd, char *str, int a);
t_print				parse_octal(t_print node, char c);
char				*ft_uitoa(uint64_t n);
t_print				parse_pointer(t_print node);
t_print				parse_float(t_print node);
__uint64_t			ft_power(int base, int power);
char				*ft_strcpy_special_edition(char *dest, const char *src);
t_print				print_color(t_print node);
t_print				parse_binary(t_print node);
void				buffer_color(t_print *node, const char *color);
t_print				parse_unicode(t_print node);
void				parse_bits(void *nbr, int size, t_print *node);
t_print				get_precision2(t_print node);
void				get_size2(t_print *node);
void				parse_hexodecimal2(t_print *node, char c, char *str);
void				parse_hexodecimal3(t_print *node, char **str, char c);
void				parse_decimal2(t_print *node, char **str);
void				parse_decimal3(t_print *node, char **str);
void				parse_decimal4(t_print *node, char **str);
void				parse_float2(t_print *node, int *a, int *pres, char **str2);
void				parse_float3(__int64_t *num, char **str2, int *a);
void				parse_float4(t_print *node, char **tmp,
										char **str, char **str2);
void				parse_float5(t_print *node, __int64_t *num, char **str);
void				parse_float6(t_print *node, __int64_t *num);
void				parse_float7(t_print *node, __int64_t *num, char **str);
void				parse_float8(t_print *node, __int64_t *num, char **str);
char				*float_cut(__int64_t *num, t_print *node,
											int *pres, char **str2);
void				parse_udecimal2(t_print *node, char **str);
void				parse_octal2(t_print *node, char **str, char c);
void				parse_octal3(t_print *node, char **str);
void				parse_pointer2(t_print *node, char **str);
void				parse_string2(t_print *node, char **str);
t_print				print_arg(t_print node);
void				check_overflow(t_print *node);

#endif
