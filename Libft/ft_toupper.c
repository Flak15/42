static int ft_islower(int c)
{
  return (c >= 'a' && c <= 'z');
}

int ft_toupper(int c)
{
  return (ft_islower(c) ? c - 32 : c);
}