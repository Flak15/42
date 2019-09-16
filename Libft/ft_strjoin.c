#include "libft.h"
#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t  len;
    char    *ns;

    if (!s1 || !s2)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2);
    ns = (char *)malloc(len + 1);
    if (!ns)
        return (NULL);
    while (*s1)
        *ns++ = *s1++;
    while (*s2)
        *ns++ = *s2++;
    *ns = '\0';
    return (ns);
}