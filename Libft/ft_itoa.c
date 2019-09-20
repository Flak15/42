#include "libft.h"
#include <stdlib.h>

static size_t		get_numlen(int num)
{
	size_t	len;

	len = 0;
	while (num % 10 != num)
	{
		num /= 10;
		++len;
	}
	return (len + 1);
}

char *ft_itoa(int num)
{
    char *ns;
    int i;
    int sign;
    long lnum;

    ns = ft_strnew(get_numlen(num) + (num < 0 ? 1 : 0));
    if (ns == NULL)
        return (NULL);
    lnum = (sign = num) < 0 ? -(long)num : num;
    i = 0;
    if (lnum == 0)
        ns[i++] = '0';
    while  (lnum > 0)
    {
        ns[i++] = lnum % 10 + '0';
        lnum /= 10;
    }
    if (sign < 0)
        ns[i++] = '-';
    ns[i] = '\0';
    return (ft_strrev(ns));
}