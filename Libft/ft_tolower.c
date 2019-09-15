static int ft_isupper(int c)
{
  return (c >= 'A' && c <= 'Z');
}

int ft_tolower(int c)
{
  return (ft_isupper(c) ? c + 32 : c);
}