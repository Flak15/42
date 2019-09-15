#include "libft.h"

char *ft_strnew(size_t size)
{
    void *str;
    str = malloc(size);
    if (!str)
        return (NULL);
    ft_bzero(str, size);
    return ((char *)str);
}
