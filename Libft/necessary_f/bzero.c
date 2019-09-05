#include <string.h>

void  bzero(void *b, size_t length)
{
	char *p;

  p = b;
  while (length--)
    *p++ = '\0';	
}
