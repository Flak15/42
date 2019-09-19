#include "libft.h"
#include <stdlib.h>

static size_t		get_num_len(size_t num)
{
	size_t	len;

	len = 0;
	while (num >= 10)
	{
		num /= 10;
		++len;
	}
	return (len + 1);
}

char *ft_itoa(int num)
{
    char *buf;
    char *ptr;

    buf = (char *)malloc(get_num_len(num) + 1 + (num < 0 ? 1 : 0));
    if (!buf)
        return (NULL);
    ptr = buf + get_num_len(num) + 1 + (num < 0 ? 1 : 0);
    *ptr-- = 0;
    if (num < 0)
    {
        while (num != 0) 
        {
            *--ptr = '0' - (num % 10);
            num /= 10;
        }
        *--ptr = '-';
        return (ptr);
    }
    else
        while (1) 
        {
            *--ptr = '0' + (num % 10);
            num /= 10;
            if (num == 0)
                break ;
        }
    return (ptr);
}

// #include <stdio.h>

// int main(void)
// {
//     printf("%s", ft_itoa(-2147483648));
//     return (0);
// }