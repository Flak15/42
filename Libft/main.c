#include "libft.h"
#include <stdio.h>

int main(void)
{
    char s[] = "";
    char s1[] = "";
    int res = strcmp(ft_strtrim("\t\t\n\t\t   "), "");
    // int res = strcmp("", "");
    printf("%d", res);
    // ft_putstr(ft_strtrim("\t\t\n\t\t   "));
    
    return (0);
}