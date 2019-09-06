void ft_strmapi(char *s, void (*f)(unsigned int, char *))
{
  int cnt;

  cnt = 0;
  if (!s)
    return (NULL);
  while(*str)
    (*f)(cnt++, *s++);
}
