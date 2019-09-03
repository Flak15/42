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

int ft_strcmp(char *s1, char *s2)
{
  while (*s1 == *s2++)
  {

    if (*s1 == '\0')
      return (0);
    s1++;
  }
  return (*s1 - *(s2 - 1));
}

int main(int argc, char **argv)
{
  int i;

  i = 1;
  while (i < argc)
  {
    ft_putstr(argv[i]);
    ft_putchar('\n');
    i++;
  }
  return (0);
}
