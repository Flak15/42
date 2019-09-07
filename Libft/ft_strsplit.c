#include <stdio.h>

static char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *ns;
    char *res;

    if (!len)
        return (NULL);
    ns = (char *)malloc(len + 1);
    res = ns;
    if (!ns)
        return (NULL);
    while(start--)
        s++;
    while(len--)
        *ns++ = *s++;
    return (res);
}

char **ft_strsplit(char const *s, char c)
{
    char **ss;

    if (!s)
        return (NULL);

    ss = NULL;
    while(*s == c)
        s++;
    
    printf("%c", *s);
    return (ss);
}

int main(void)
{
    ft_strsplit(":::::abc:ggg:ooo:xxx", ':');
    return (0);
}