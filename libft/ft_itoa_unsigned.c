/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iulia <iulia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:36:33 by iulia             #+#    #+#             */
/*   Updated: 2020/07/14 21:51:24 by iulia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_nbr_len(n);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (len-- > i)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
