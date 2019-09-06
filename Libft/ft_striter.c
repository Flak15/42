#include <string.h>

void ft_striter(char *s, void (*f)(char *))
{
  if (!s)
    return ;
  while(*s)
    *s = (void *)(*f)(s++);
}
