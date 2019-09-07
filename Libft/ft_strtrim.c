#include <stdlib.h>
#include <stdio.h>
static int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static size_t ft_strlen(const char *str)
{
	const char *s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

static char *ft_strncpy(char *dst, const char *src, size_t n)
{
  char *d = dst;
  char *s = (char *)src;

  if (n)
  {
    while (1)
    {
      *d++ = *s++;
      if (*s == '\0')
      {
        while (--n != 0)
        {
          *d = '\0';
          d++;
        }
        break ;
      }
      if (--n == 0)
        break;
    }
  }
  return (dst);
}

char *ft_strtrim(char const *s)
{
	char *ns;
	char *start;
	char *end;
	size_t len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = (char *)s;
	end = (char *)s + len - 1;
	while (ft_isspace(*start))
		start++;
	while (ft_isspace(*end))
		end--;
	ns = (char *)malloc(end - start + 2);
	if (!ns)
		return (NULL);
	// *ns = *start;
	ft_strncpy(ns, start, end - start + 1);
	// printf("len:%ld\n", end - start + 1);
	printf("%s", ns);
	return (ns);
}

int main(void)
{

	char str[] = "   1234567 11   ";
	ft_strtrim(str);
	return (0);
}