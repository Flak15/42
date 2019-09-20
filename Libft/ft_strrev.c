#include "libft.h"

char *ft_strrev(char *s)
{
    int i;
    int j;
    char c;

    if (!s || !*s)
        return (s);
    i = 0;
    j = ft_strlen(s) - 1;
    while (i < j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
    return (s);
}