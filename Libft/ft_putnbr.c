#include <string.h>
#include <stdlib.h>

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

static void ft_putstr(char const *s)
{
    if (!s)
        return ;
    while (*s)
        write(1, s, 1);
}

void ft_putnbr(int n)
{
    ft_putstr(ft_itoa(n));
}