int ft_putchar(char c);

void ft_putstr(char *str)
{
  if (!str)
    return ;
  while (*str)
  {
    ft_putchar(*str);
    str++;
  }
}
