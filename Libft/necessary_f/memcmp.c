#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
  const unsigned char *p1;
  const unsigned char *p2;

  p1 = s1;
  p2 = s2;
  if (n) {
		while (1)
    {
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
      if (--n == 0)
        break;
		}
	}
	return (0);
}
