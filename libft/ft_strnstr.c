/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iulias <iulias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:56:00 by iulias            #+#    #+#             */
/*   Updated: 2020/06/02 17:40:03 by iulias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char*)big);
	while (big[i] && i < l)
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j < l) && (little[j]))
			j++;
		if (!little[j])
			return ((char*)&big[i]);
		i++;
	}
	return (NULL);
}
