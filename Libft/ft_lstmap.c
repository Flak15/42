#include "libft.h"
#include <stdlib.h>

void ft_clear_elem(void *content, size_t content_size)
{
	content_size = content_size;
	free(content);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
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