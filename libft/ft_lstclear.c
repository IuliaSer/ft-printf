/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iulias <iulias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:33:52 by iulias            #+#    #+#             */
/*   Updated: 2020/06/02 23:07:41 by iulias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *a;

	if (del)
	{
		while (*lst != NULL)
		{
			a = *lst;
			*lst = a->next;
			del(a->content);
			free(a);
		}
	}
	*lst = NULL;
}
