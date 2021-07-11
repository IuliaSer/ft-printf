/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iulia <iulia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:41:48 by iulias            #+#    #+#             */
/*   Updated: 2020/07/12 13:23:24 by iulia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_sign(int n, int sign)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		if (sign)
			ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr_sign(n / 10, sign);
	ft_putchar(n % 10 + '0');
	return ;
}
