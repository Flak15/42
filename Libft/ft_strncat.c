#include "libft.h"

char *ft_strncat(char *str, const char *append, size_t n)
{
    size_t len1 = strlen(str);
    size_t len2 = strlen(append);
    
    if (len2 < n) 
    {
	    strcpy(&str[len1], append);
    } 
    else 
    {
        strncpy(&str[len1], append, n);
        str[len1 + n] = '\0';
    }
    return (str);
}
