#include <string.h>

void *ft_memset(void *dst, int c, size_t n)
{
	unsigned char *d;
	if (n != 0) {
		d = dst;
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
