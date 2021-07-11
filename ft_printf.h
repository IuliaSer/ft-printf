/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:22:13 by iulias            #+#    #+#             */
/*   Updated: 2020/07/28 17:32:49 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define MIN_INT -2147483648

typedef struct	s_format
{
	int			zero;
	int			minus;
	int			width;
	char		*conv_specifiers;
	char		*flags;
	int			precision;
	int			nbr_sign;
	int			empty;
	int			pointer;
}				t_format;

int				ft_printf(const char *str, ...);
int				ft_size(int nbr);
int				ft_strsize(char *s);
t_format		*init_format();
size_t			parse_format(char *str, va_list ap, t_format *format);
int				ft_print(char *str, t_format *format);
int				parse_int(int nbr, t_format *format);
int				print_char(char c, t_format *format);
int				parse_int_unsigned(char *str, unsigned int nbr,
t_format *format);
int				parse_str(char *nstr, t_format *format);
char			*convert_pointer(t_format *format, unsigned long n, int base);
int				parse_pointer(unsigned long nbr, t_format *format);

#endif
