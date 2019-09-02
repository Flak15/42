int ft_strlen(char *str)
{
  int cnt;

  cnt = 0;
  if (!str)
    return (0);
  while (*str)
  {
    str++;
    cnt++;
  }
  return (cnt);
}
