/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 10:45:41 by iulia             #+#    #+#             */
/*   Updated: 2020/07/27 19:26:36 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(char c, t_format *format)
{
	int		blnks;
	int		len;

	len = 0;
	if (format->width)
	{
		blnks = format->width - 1;
		len = blnks;
	}
	if (format->zero && format->width)
	{
		while (blnks--)
			ft_putchar('0');
	}
	else if (format->width && !format->minus)
	{
		while (blnks--)
			ft_putchar(' ');
	}
	ft_putchar(c);
	while (format->width && format->minus && blnks--)
		ft_putchar(' ');
	return (len + 1);
}

static int	print_zeros(int size, t_format *format, char *str)
{
	int	len;
	int	zeros;

	zeros = 0;
	if (format->width > size)
		zeros = format->width - size;
	if (format->precision > size)
		zeros = format->precision - size;
	if (format->nbr_sign && format->precision <= -1)
		zeros--;
	len = zeros;
	if (format->pointer)
	{
		write(1, "0x", 2);
		if (format->precision == -1)
			zeros -= 2;
		len += 2;
	}
	while (zeros-- > 0)
		ft_putchar('0');
	ft_putstr(str);
	return (len);
}

static int	print_spaces(int size, t_format *format)
{
	int	len;
	int	nbr_spcs;

	len = 0;
	nbr_spcs = format->width - size;
	if (format->empty)
		nbr_spcs = format->width;
	if (format->precision > size)
		nbr_spcs = format->width - format->precision;
	if (format->pointer && (format->width > format->precision))
		nbr_spcs = format->width - format->precision - 2;
	if (format->nbr_sign)
		nbr_spcs--;
	while (nbr_spcs-- > 0)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}

int			ft_print(char *str, t_format *format)
{
	int		len;
	int		size;

	len = 0;
	size = ft_strsize(str);
	if (format->empty)
		size = 0;
	if ((!format->minus) && (format->width) && (!format->zero))
		len += print_spaces(size, format);
	if ((format->zero && format->width) || (format->precision > size))
	{
		if (format->nbr_sign)
		{
			ft_putchar('-');
			len++;
		}
		len += print_zeros(size, format, str);
	}
	else
		!format->empty ? ft_putstr(str) : ft_putstr("");
	if (format->minus && format->width && !format->zero)
		len += print_spaces(size, format);
	free(str);
	str = NULL;
	return (len + size);
}
