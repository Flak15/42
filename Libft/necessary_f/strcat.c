#include <string.h>

char *strcat(char *str, const char *append)
{
  char *save;

  save = str;
  while (*str)
    str++;
  while (1)
  {
    if (!(*str = *append))
      return (save);
    ++str;
    ++append;
  }
}
