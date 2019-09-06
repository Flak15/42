#include <string.h>

static size_t   ft_strlen(const char *str)
{
  const char *s;

  s = str;
  while (*s)
    s++;
	return (s - str);
}

static  int		ft_strncmp(char *s1, char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*s1 != *s2++)
			return (*s1 - *(s2 - 1));
		if (!*s1)
			return (0);
		s1++;
		n--;
	}
	return (0);
}

char            *strnstr(const char *s, const char *find, size_t slen)
{
	char c;
    char save_c;
	size_t len;

    c = *find;
    len = ft_strlen(find);
	if (c != '\0')
    {
        find++;
		do 
        {
			do
            {
				if ((save_c = *s++) == '\0' || slen-- < 1)
                    return (NULL);
                s++;
			} while (save_c != c);
			if (len > slen)
				return (NULL);
		} while (ft_strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}
