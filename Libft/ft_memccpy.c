#include <string.h>

void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
  unsigned char *tp = dst;
  const unsigned char *fp = src;
  unsigned char uc = c;

	if (n)
		while (1)
    {
			if ((*tp++ = *fp++) == uc)
				return (tp);
      if (--n == 0)
        break;
		}
	return (0);
}
