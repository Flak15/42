#include <stdio.h>

int ft_toupper(int c)
{
  return (ft_islower(c) ? c - 32 : c);
}

int ft_tolower(int c)
{
  return (ft_isupper(c) ? c + 32 : c);
}

static int ft_islower(int c)
{
  return (c >= 'a' && c <= 'z');
}

static int ft_isupper(int c)
{
  return (c >= 'A' && c <= 'Z');
}

int ft_isalpha(int c)
{
  return (ft_islower(c) || ft_isupper(c));
}

int ft_isdigit(int c)
{
  return (c >= '0' && c <= '9');
}

int ft_isalnum(int c)
{
  return (ft_isdigit(c) || ft_isalpha(c));
}

int ft_isascii(int c)
{
  return((c & ~0x7F) == 0);
}

int ft_isprint(int c)
{
  return (c >= 32 && c <= 126);
}

int main(void)
{
  if (ft_isalpha('1'))
    printf("al");
  return (0);
}
