#include <stdlib.h>

void ft_putstr(char const *s)
{
    if (!s)
        return ;
    while (*s)
        write(1, s, 1);
}