#include <string.h>

void *memchr(const void *s, int c, size_t n)
{
  const unsigned char *ptr = s;

	if (n)
  {
		while (1)
    {
			if (*ptr++ == (unsigned char)c)
				return ((void *)(ptr - 1));
      if (--n == 0)
        break;
		}
	}
	return (NULL);
}
