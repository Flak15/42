#include "libft.h"
#include <stdio.h>//
char *ft_strrmchr(const char *s, char c)
{
    size_t new_len;
    char *res;
    char *begin;
    const char *curr;

    curr = s;
    new_len = ft_strlen(s);
    while (*curr)
        if (*curr++ == c)
            new_len--;
    printf("%ld\n", new_len);
    res = (char *)malloc(new_len + 1);
    begin = res;
    while (*s)
    {
        if (*s != c)
            *res++ = *s;
        s++;
    }
    *res = '\0';
    return (begin);
}


int main(void)
{
    char *s = "####\n....\n....\n....\n\n....\n###.\n#...\n....\n";
    printf("%s\n", ft_strrmchr(s, '\n'));
    return 0;
}
