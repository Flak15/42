#include  <string.h>
#include <stdlib.h>

char * ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *ns;

    if (!len)
        return (NULL);
    ns = (char *)malloc(len + 1);
    if (!ns)
        return (NULL);
    while(start--)
        s++;
    while(len--)
        *ns++ = *s++;
    return (ns);
}