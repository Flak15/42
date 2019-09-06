#include <stdlib.h>

static void *ft_memalloc(size_t size)
{
  return (malloc(size));
}

static void  bzero(void *b, size_t length)
{
	char *p;

  p = b;
  while (length--)
    *p++ = '\0';
}

char *ft_strnew(size_t size)
{
  void *str;
  str = malloc(size);
  if (!str)
    return (NULL);
  bzero(str, size);
  return ((char *)str);
}
