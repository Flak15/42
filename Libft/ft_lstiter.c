#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		f(ptr);
		ptr = ptr->next;
	}
}