#define INT_DIGITS 19

char *ft_itoa(int num)
{
    static char buf[INT_DIGITS + 2];
    char *ptr;

    ptr = buf + INT_DIGITS + 1;
    if (num >= 0)
    {
        while (num != 0) 
        {
            *--ptr = '0' + (num % 10);
            num /= 10;
        } 
        return (ptr);
    }
    else
    {
        while (num != 0) 
        {
            *--ptr = '0' - (num % 10);
            num /= 10;
        }
        *--ptr = '-';
    }
    return (ptr);
}
