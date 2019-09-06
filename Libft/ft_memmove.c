#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
  char *d;
  const char *s;
  char *lasts;
  char *lastd;

  d = dst;
  s = src;
  lasts = s + (len-1);
  lastd = d + (len-1);
  if (d < s)
    while (len--)
      *d++ = *s++;
  else
      while (len--)
        *lastd-- = *lasts--;
  return (dst);
}
