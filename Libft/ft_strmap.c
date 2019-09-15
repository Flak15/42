#include "libft.h"
#include <stdlib.h>

char *ft_strmap(char const *s, char (*f)(char))
{
	size_t len;
	char *ns;
	char *save_ns;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ns = (char *)malloc(len + 1);
	if (!ns)
		return (NULL);
	save_ns = ns;
	while(*s)
	{
		*ns = f(*s++);
		ns++;
	}
	return (save_ns);
}
