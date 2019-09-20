#include "libft.h"

char *ft_strncat(char *restrict str, const char *restrict append, size_t n)
{
    size_t len1 = ft_strlen(str);
    size_t len2 = ft_strlen(append);
    
    if (len2 < n) 
    {
	    ft_strcpy(&str[len1], append);
    } 
    else 
    {
        ft_strncpy(&str[len1], append, n);
        str[len1 + n] = '\0';
    }
    return (str);
}
