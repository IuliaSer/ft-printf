/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:50:18 by iulias            #+#    #+#             */
/*   Updated: 2020/07/28 17:32:31 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		parse_format(char *str, va_list ap, t_format *format)
{
	int		len;

	len = 0;
	if ((format->precision >= 0) || (format->minus && format->zero))
		format->zero = 0;
	if (*str == 'd' || *str == 'i')
		len = parse_int(va_arg(ap, int), format);
	if (*str == 'u' || *str == 'x' || *str == 'X')
		len = parse_int_unsigned(str, va_arg(ap, unsigned int), format);
	if (*str == '%')
		len = print_char('%', format);
	if (*str == 's')
		len = parse_str(va_arg(ap, char *), format);
	if (*str == 'c')
		len = print_char((char)va_arg(ap, int), format);
	if (*str == 'p')
		len = parse_pointer((unsigned long)va_arg(ap, void *), format);
	return (len);
}

int			parse_pointer(unsigned long nbr, t_format *format)
{
	char	*temp;
	char	*str;
	int		size;

	str = convert_pointer(format, nbr, 16);
	temp = str;
	size = ft_strsize(str);
	if (format->precision > size || (format->zero && (format->width > size)))
	{
		str = ft_substr(str, 2, size - 2);
		free(temp);
		format->pointer = 1;
	}
	return (ft_print(str, format));
}

int			parse_int(int nbr, t_format *format)
{
	char	*nstr;
	char	*temp;

	if (nbr < 0 && ((format->precision >= ft_size(nbr)) ||
	(format->zero && (format->width > ft_size(nbr)))))
	{
		if (nbr == MIN_INT)
		{
			nstr = ft_itoa(nbr);
			temp = nstr;
			nstr = ft_substr(nstr, 1, 10);
			free(temp);
			format->nbr_sign = 1;
			return (ft_print(nstr, format));
		}
		nbr = nbr * -1;
		format->nbr_sign = 1;
	}
	if (format->precision == 0 && nbr == 0)
		format->empty++;
	nstr = ft_itoa(nbr);
	return (ft_print(nstr, format));
}

int			parse_int_unsigned(char *str, unsigned int nbr, t_format *format)
{
	char	*nstr;
	int		i;

	nstr = NULL;
	i = 0;
	if (format->precision == 0 && nbr == 0)
		format->empty++;
	if (*str == 'u')
		nstr = ft_itoa_unsigned(nbr);
	else if (*str == 'x' || *str == 'X')
	{
		nstr = ft_itoa_base(nbr, 16);
		if (*str == 'X')
		{
			while (nstr[i])
			{
				nstr[i] = (char)ft_toupper(nstr[i]);
				i++;
			}
		}
	}
	return (ft_print(nstr, format));
}

int			parse_str(char *nstr, t_format *format)
{
	char	*temp;

	if (!nstr)
	{
		nstr = ft_strdup("(null)");
		if (format->precision == 0)
			format->empty++;
	}
	else
		nstr = ft_strdup(nstr);
	temp = nstr;
	if (format->precision < ft_strsize(nstr) && format->precision != -1)
	{
		nstr = ft_substr(nstr, 0, format->precision);
		free(temp);
		temp = 0;
	}
	if (format->precision == 0)
		format->empty++;
	if (format->precision > ft_strsize(nstr))
		format->precision = -1;
	return (ft_print(nstr, format));
}
