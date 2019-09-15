void ft_striteri(char *str, void (*f)(unsigned int, char *))
{
  int cnt;

  cnt = 0;
  if (!str)
    return ;
  while(*str)
    (*f)(cnt++, str++);

}
