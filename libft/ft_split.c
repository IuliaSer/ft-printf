/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iulias <iulias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 12:46:11 by iulias            #+#    #+#             */
/*   Updated: 2020/06/14 23:16:57 by iulias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words_count(char const *s, char c)
{
	int		i;
	size_t	word;
	int		flag;

	word = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			word++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (word);
}

static size_t	ft_word_length(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static void		*ft_free_arr(char **arr, int i)
{
	int	j;

	j = 0;
	if (arr)
	{
		while (j < i)
			free(arr[j++]);
		free(arr);
	}
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	j;
	size_t	i;
	size_t	len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(arr = (char**)malloc(sizeof(char*) * (ft_words_count(s, c) + 1))))
		return (NULL);
	while (j < ft_words_count(s, c))
	{
		while (s[i] == c)
			i++;
		len = ft_word_length(s + i, c);
		arr[j] = ft_substr(s, i, len);
		if (arr[j] == NULL)
			return (ft_free_arr(arr, j));
		i = i + len;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
