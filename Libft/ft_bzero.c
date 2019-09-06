#include <string.h>

void  ft_bzero(void *b, size_t length)
{
	char *p;

  p = b;
  while (length--)
    *p++ = '\0';
}
