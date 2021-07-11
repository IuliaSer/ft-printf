/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 22:17:45 by iulia             #+#    #+#             */
/*   Updated: 2020/07/24 16:46:44 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr_len(t_format *format, unsigned long nbr, int base)
{
	int	len;

	len = 0;
	if (nbr == 0 && format->precision == 0)
		return (0);
	else if (nbr == 0 && format->precision != 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / base;
		len++;
	}
	return (len);
}

char		*convert_pointer(t_format *format, unsigned long n, int base)
{
	char	*str;
	char	*res;
	int		len;

	str = "0123456789abcdef";
	len = ft_nbr_len(format, n, base) + 2;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[0] = '0';
	res[1] = 'x';
	res[len] = '\0';
	while (--len > 1)
	{
		res[len] = str[n % base];
		n = n / base;
	}
	return (res);
}
