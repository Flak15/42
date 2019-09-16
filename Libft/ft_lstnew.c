#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

    list = (t_list*)ft_memalloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_dup(content, content_size);
		if (list->content == NULL)
			return (NULL);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}