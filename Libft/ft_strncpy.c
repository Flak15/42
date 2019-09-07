#include <string.h>

char *ft_strncpy(char *dst, const char *src, size_t n)
{
  char *d = dst;
  char *s = (char *)src;

  if (n)
  {
    while (1)
    {
      *d++ = *s++;
      if (*s == '\0')
      {
        while (--n != 0)
        {
          *d = '\0';
          d++;
        }
        break ;
      }
      if (--n == 0)
        break;
    }
  }
  return (dst);
}
