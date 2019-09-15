char *ft_strcpy(char *dest, const char *src)
{
    char *save;

    save = dest;
    while ((*dest = *src))
    {
        dest++;
        src++;
    }
    return (save);
}
