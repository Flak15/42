char *ft_strstr(const char *str, const char *to_find)
{
    char *s;
    char *f;

    if (!to_find)
        return ((char *)str);
    while (*str)
    {
        s = (char *)str;
        f = (char *)to_find;
        while (*s && *f && !(*f - *s))
        {
            s++;
            f++;
        }
        if (!*f)
            return ((char *)str);
        str++;
    }
    return (0);
}
