#include <string.h>

void *memset(void *dst, int c, size_t n)
{
	if (n != 0) {
		unsigned char *d = dst;

		while (1)
    {
			*d = (unsigned char)c;
      d++;
	    if (--n == 0)
        break;
    }
	}
	return (dst);
}
