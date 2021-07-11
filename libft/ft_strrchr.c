/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iulias <iulias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:45:48 by iulias            #+#    #+#             */
/*   Updated: 2020/05/19 19:47:44 by iulias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char*)&s[len]);
	len = len - 1;
	while (s[len])
	{
		if (s[len] == (char)c)
			return ((char*)&s[len]);
		if (len == 0)
			return (NULL);
		len--;
	}
	return (NULL);
}
