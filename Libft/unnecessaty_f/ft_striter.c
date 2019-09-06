void ft_striter(char *s, void (*f)(char *))
{
  if (!s)
    return (NULL);
  while(*str)
    *s = (*f)(*s++);
}
