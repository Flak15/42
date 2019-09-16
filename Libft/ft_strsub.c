#include  "libft.h"
#include <stdlib.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *res;

    if (!len)
        return (NULL);
    res = (char *)malloc(len + 1);
    if (!res)
        return (NULL);
    res = ft_strncpy(res, (char *)s + start, len);
    return (res);
}
