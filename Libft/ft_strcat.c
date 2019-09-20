char *ft_strcat(char *restrict str, const char *restrict append)
{
    char *save;

    save = str;
    while (*str)
        str++;
    while (1)
    {
        if (!(*str = *append))
            return (save);
        ++str;
        ++append;
    }
}
