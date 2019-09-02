int   ft_putchar(char c);

void ft_print_alphabet(void)
{
  int ch = 'a';
  while (ch <= 'z')
  {
    ft_putchar(ch);
    ch++;
  }
}
