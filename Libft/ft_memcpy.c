#include <string.h>

void *ft_memcpy(void *restrict dst0, const void *restrict src0, size_t length)
{
  	char *dst = dst0;
	const char *src = src0;

  if (length == 0 || dst == src)
  		return (dst0);
  while (length--)
      *dst++ = *src++;
  return (dst0);
}
