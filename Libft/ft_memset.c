#include "libft.h"

void *ft_memset(void *dst, int c, size_t n)
{
	unsigned char *d;

	if (n) 
    {
		d = (unsigned char *)dst;
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
