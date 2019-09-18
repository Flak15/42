#include "libft.h"

char *ft_strncpy(char *dst, const char *src, size_t n)
{
    char *d;
    char *s;

    d = dst;
    s = (char *)src;
    if (n)
        while (1)
        {
            *d++ = *s++;
            if (*(s - 1) == '\0')
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
    return (dst);
}
