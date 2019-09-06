char *ft_strstr(const char *str0, const char *to_find0) //to fix
{
    char *str;
    char *to_find;
    to_find = to_find0;
    str = str0;
    char *s;
    char *f;

    if (!to_find)
        return str;
    while (*str)
    {
        s = str;
        f = to_find;
        while (*s && *f && !(*f - *s))
        {
            s++;
            f++;
        }
        if (!*f)
            return (str);
        str++;
    }
    return (0);
}

// char    *my_strstr(const char *haystack, const char *needle)
// {
//     size_t  needle_len;
//
//     needle_len = strlen(needle);
//     while (*haystack)
//     {
//         if (*haystack == *needle)
//         {
//             if (!strncmp(haystack, needle, needle_len))
//                     return ((char *)haystack);
//         }
//         haystack++;
//     }
//     return (NULL);
// }
