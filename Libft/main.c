#include "libft.h"
#include <stdio.h>

int main(void)
{
    char str[] = "abc";
    char s1[] = "";
    int res = strcmp(ft_strsub(str,0 , 0), "");
    // int res = strcmp("", "");
    printf("%d", res);
    // ft_putstr(ft_strtrim("\t\t\n\t\t   "));
    
    return (0);
}