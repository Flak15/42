void ft_strmap(char *s, void (*f)(char *))
{
  if (!s)
    return (NULL);
  while(*str)
    (*f)(*s++);
}
