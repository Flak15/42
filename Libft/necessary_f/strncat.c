#include <string.h>

char *strncat(char *str, const char *append, size_t n)
{
  char *save;
  if (n == 0)
    return (str);

  save = str;
  while (*str)
    str++;
  while (n != 1)
  {
    if (!(*str = *append))
      return (save);
    ++str;
    ++append;
    --n;
  }
  *str = 0;
  return (save);
}
