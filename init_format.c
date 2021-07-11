/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:10:49 by iulias            #+#    #+#             */
/*   Updated: 2020/07/28 17:32:40 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*init_format(void)
{
	t_format	*format;

	if (!(format = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	format->zero = 0;
	format->minus = 0;
	format->width = 0;
	format->conv_specifiers = "cspdiuxX%";
	format->flags = "-0*.123456789";
	format->precision = -1;
	format->nbr_sign = 0;
	format->empty = 0;
	format->pointer = 0;
	return (format);
}
