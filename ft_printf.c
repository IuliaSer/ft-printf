/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:52:05 by iulias            #+#    #+#             */
/*   Updated: 2020/07/28 17:41:44 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_strchr_mod(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char*)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

static int		put_width(char *str, va_list ap, t_format *format)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (str[i] == '*')
	{
		format->width = va_arg(ap, int);
		if (format->width < 0)
		{
			format->width *= -1;
			format->minus++;
		}
		return (++i);
	}
	format->width = ft_atoi(str);
	return (ft_size(format->width) + i);
}

static int		put_precision(char *str, va_list ap, t_format *format)
{
	int	i;

	i = 0;
	if (str[i] == '*')
	{
		format->precision = va_arg(ap, int);
		return (++i);
	}
	if (str[i] == '0')
		i++;
	format->precision = ft_atoi(&str[i]);
	return (ft_size(format->precision) + i);
}

static char		*parse_flags(char *str, va_list ap, t_format *format)
{
	size_t	i;

	i = 0;
	while (str[i] == '-' || ft_isdigit(str[i]) || str[i] == '*'
	|| str[i] == '.')
	{
		if (str[i] == '0')
			format->zero++;
		if (str[i] == '-')
			format->minus++;
		if (ft_isdigit(str[i]) || str[i] == '*')
			i = i + put_width(&str[i], ap, format);
		else if (str[i] == '.')
		{
			i++;
			i = i + put_precision(&str[i], ap, format);
		}
		else
			i++;
	}
	return (&str[i]);
}

int				ft_printf(const char *str, ...)
{
	t_format	*format;
	va_list		ap;
	size_t		len;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			format = init_format();
			if (ft_strchr_mod(format->flags, *str))
				str = parse_flags((char *)str, ap, format);
			if (ft_strchr_mod(format->conv_specifiers, *str))
				len += parse_format((char *)str++, ap, format);
			free(format);
			format = NULL;
		}
		else if (*str)
			len += write(1, str++, 1);
	}
	va_end(ap);
	return (len);
}
