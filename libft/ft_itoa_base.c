/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:29:07 by iulia             #+#    #+#             */
/*   Updated: 2020/07/24 17:43:40 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(unsigned int nbr, int base)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(unsigned int n, int base)
{
	char	*str;
	char	*res;
	int		i;
	int		len;

	str = "0123456789abcdef";
	len = ft_nbr_len(n, base);
	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (len-- > i)
	{
		res[len] = str[n % base];
		n = n / base;
	}
	return (res);
}
