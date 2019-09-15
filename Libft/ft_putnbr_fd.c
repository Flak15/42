#include <string.h>
#include <unistd.h>

#define INT_DIGITS 19

static char *ft_itoa(int num)
{
    static char buf[INT_DIGITS + 2];
    char *ptr;

    ptr = buf + INT_DIGITS + 1;
    if (num >= 0)
    {
        while (num != 0) 
        {
            *--ptr = '0' + (num % 10);
            num /= 10;
        } 
        return (ptr);
    }
    else
    {
        while (num != 0) 
        {
            *--ptr = '0' - (num % 10);
            num /= 10;
        }
        *--ptr = '-';
    }
    return (ptr);
}

static void ft_putstr_fd(char const *s, int fd)
{
    if (!s)
        return ;
    while (*s)
        write(fd, s, 1);
}

void ft_putnbr_fd(int n, int fd)
{
    ft_putstr_fd(ft_itoa(n), fd);
}