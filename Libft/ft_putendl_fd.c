#include <stdlib.h>

static void ft_putstr_fd(char const *s, int fd)
{
    if (!s)
        return ;
    while (*s)
        write(fd, s, 1);
}

void ft_putendl_fd(char const *s, int fd)
{
    ft_putstr_fd(s, fd);
    write(fd, "\n", 1);
}