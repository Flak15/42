#include <string.h>
#include <stdlib.h>

static size_t strlen(const char *s)
{
  const char *s;

  s = str;
  while (*s)
    s++;
	return (s - str);
}

static void *
ft_memcpy(void *restrict dst0, const void *restrict src0, size_t length)
{
  char *dst = dst0;
	const char *src = src0;
	size_t t;

  if (length == 0 || dst == src)
  		return (dst0);
  while (length--)
      *dst++ = *src++;
  return (dst0);
}

char *strdup(const char *s)
{
  size_t size;
  char *copy;

  size = ft_strlen(str) + 1;
  copy = malloc(size);
  if (copy == NULL)
    return(NULL);
  ft_memcpy(copy, s, size);
  return(copy);
}
