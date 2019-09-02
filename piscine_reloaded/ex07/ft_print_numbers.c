int   ft_putchar(char c);

void ft_print_numbers(void)
{
  int nb;

  nb = '0';
  while (nb <= '9')
  {
    ft_putchar(nb);
    nb++;
  }
}
