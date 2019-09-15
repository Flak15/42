#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *str)
{
    size_t size;
    char *copy;

    size = ft_strlen(str) + 1;
    copy = (char *)malloc(size);
    if (!copy)
        return (NULL);
    ft_memcpy(copy, str, size);
    return (copy);
}
