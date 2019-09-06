void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
  int cnt;

  cnt = 0;
  if (!s)
    return (NULL);
  while(*str)
    *s = (*f)(cnt++, *s++);
}
