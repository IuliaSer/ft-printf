/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iulias <iulias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 19:27:53 by iulias            #+#    #+#             */
/*   Updated: 2020/06/01 20:03:34 by iulias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrim_begin(char *str, char const *set, size_t lset)
{
	size_t i;
	size_t j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (i < lset)
		{
			if (str[j] == set[i])
			{
				j++;
				break ;
			}
			i++;
		}
		if (i == lset)
			return (j);
	}
	return (j);
}

static size_t	ft_strtrim_end(char *str, char const *set, size_t lset, \
size_t len)
{
	size_t	i;
	size_t	j;

	j = len - 1;
	while (str[j])
	{
		i = 0;
		while (i < lset)
		{
			if (str[j] == set[i])
			{
				len--;
				break ;
			}
			i++;
		}
		if (i == lset)
			return (len);
		j--;
	}
	return (len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	lset;
	size_t	len;
	size_t	j;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char*)s1);
	str = (char*)s1;
	j = 0;
	lset = ft_strlen(set);
	len = ft_strlen(s1);
	i = ft_strtrim_begin(str, set, lset);
	if (len != i)
		len = ft_strtrim_end(str, set, lset, len) - i;
	else
		len = len - i;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	while (j < len)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
