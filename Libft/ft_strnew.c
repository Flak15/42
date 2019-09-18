#include "libft.h"
#include <stdlib.h>

char *ft_strnew(size_t size)
{
    void *str;
    str = malloc(size + 1);
    if (!str)
        return (NULL);
    ft_bzero(str, size + 1);
    return ((char *)str);
}
