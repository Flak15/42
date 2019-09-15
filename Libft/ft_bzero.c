#include "libft.h"

void  ft_bzero(void *b, size_t length)
{
	char *p;

	p = (char *)b;
	while (length--)
		*p++ = '\0';
}
