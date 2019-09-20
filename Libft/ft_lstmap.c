/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:52:59 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 16:53:15 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_clear_elem(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*curr;
	t_list		*first;

	if (!lst)
		return (NULL);
	first = f(lst);
	curr = first;
	while (lst->next)
	{
		lst = lst->next;
		curr->next = f(lst);
		if (!(curr->next))
		{
			ft_lstdel(&first, &ft_clear_elem);
			return (NULL);
		}
		curr = curr->next;
	}
	return (first);
}
