#include <stdlib.h>

static void ft_putstr(char const *s)
{
    if (!s)
        return ;
    while (*s)
        write(1, s, 1);
}

void ft_putendl(char const *s)
{
    if (!s)
        return ;
    ft_putstr(s);
    write(1, "\n", 1);
}