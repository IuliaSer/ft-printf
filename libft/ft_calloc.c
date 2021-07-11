/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iulias <iulias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:37:33 by iulias            #+#    #+#             */
/*   Updated: 2020/05/31 10:40:10 by iulias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (!(arr = (malloc(nmemb * size))))
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}
